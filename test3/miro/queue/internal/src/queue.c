#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#include "queue.h"
#include "list.h"

static int addB(queue_object *obj, int key, datum d);
static int addE(queue_object *obj, int key, datum d);
static int getB(queue_object *obj, int *key, datum *d);
static int getE(queue_object *obj, int *key, datum *d);
static void begin_crit(queue_object *obj);
static void end_crit(queue_object *obj);
static void *search(queue_object *obj, int key, datum *d);
static void *addL(queue_object *obj, void *_lp, int key, datum d);
static void *addR(queue_object *obj, void *_lp, int key, datum d);
static void del(queue_object *obj, void *_lp);
static void *iterB(queue_object *obj, void *_lp, int *key, datum *d, int *valid);
static void *iterE(queue_object *obj, void *_lp, int *key, datum *d, int *valid);

queue_object *queue_create(void) {
	queue_object *obj;
	queue_head *q;
	pthread_mutex_t qmtx = PTHREAD_MUTEX_INITIALIZER;
	
	if (!(obj = (queue_object *)calloc(1, sizeof (*obj)))) goto bad0;
	if (!(q = (queue_head *)calloc(1, sizeof(*q)))) goto bad1;
	
	memcpy(&q->qmtx, &qmtx, sizeof (qmtx));
	obj->queue = q;
	obj->addB = &addB;
	obj->addE = &addE;
	obj->addL = &addL;
	obj->addR = &addR;
	obj->getB = &getB;
	obj->getE = &getE;
	obj->begin_crit = &begin_crit;
	obj->end_crit = &end_crit;
	obj->search = &search;
	obj->del = &del;
	obj->iterB = &iterB;
	obj->iterE = &iterE;
	
	return obj;
	
bad1:
	free(obj);
bad0:
	return NULL;
}

void queue_delete(queue_object *obj) {
	queue_head *q = (queue_head *)obj->queue;
	list *l, *t;
	
	pthread_mutex_lock(&q->qmtx);
	
	l = q->B;
	
	while (l) {
		t = l;
		l = l->next;
		
		if (t->d.on_delete) t->d.on_delete(&t->d);
		free(t);
	}
	
	free(q);
	free(obj);
	
	return;
}

static int addB(queue_object *obj, int key, datum d) {
	queue_head *q = (queue_head *)obj->queue;
	list *l;
	
	pthread_mutex_lock(&q->qmtx);
	
	if (!(l = (list *)calloc(1, sizeof(list)))) return 0;
	
	l->key = key;
	l->d = d;
	
	if (q->B) {
		l->next = q->B;
		q->B->prev = l;
		q->B = l;
	} else q->B = q->E = l;
	
	pthread_mutex_unlock(&q->qmtx);
	
	return 1;
}

static int addE(queue_object *obj, int key, datum d) {
	queue_head *q = (queue_head *)obj->queue;
	list *l;
	
	pthread_mutex_lock(&q->qmtx);
	
	if (!(l = (list *)calloc(1, sizeof(list)))) return 0;
	
	l->key = key;
	l->d = d;
	
	if (q->E) {
		l->prev = q->E;
		q->E->next = l;
		q->E = l;
	} else q->B = q->E = l;
	
	pthread_mutex_unlock(&q->qmtx);
	
	return 1;
}

static int getB(queue_object *obj, int *key, datum *d) {
	queue_head *q = (queue_head *)obj->queue;
	list *l;
	
	pthread_mutex_lock(&q->qmtx);
	
	if (!q->B) return 0;
	
	l = q->B;
	if (l->next) {
		q->B = l->next;
		q->B->prev = NULL;
	} else q->B = q->E = NULL;
	
	if (key) *key = l->key;
	*d = l->d;
	
	free(l);
	
	pthread_mutex_unlock(&q->qmtx);
	
	return 1;
}

static int getE(queue_object *obj, int *key, datum *d) {
	queue_head *q = (queue_head *)obj->queue;
	list *l;
	
	pthread_mutex_lock(&q->qmtx);
	
	if (!q->E) return 0;
	
	l = q->E;
	if (l->prev) {
		q->E = l->prev;
		q->E->next = NULL;
	} else q->B = q->E = NULL;
	
	if(key) *key = l->key;
	*d = l->d;
	
	free(l);
	
	pthread_mutex_unlock(&q->qmtx);
	
	return 1;
}

static void begin_crit(queue_object *obj) {
	queue_head *q = (queue_head *)obj->queue;
	
	pthread_mutex_lock(&q->qmtx);
	return;
}

static void end_crit(queue_object *obj) {
	queue_head *q = (queue_head *)obj->queue;
	
	pthread_mutex_unlock(&q->qmtx);
	return;
}

static void *search(queue_object *obj, int key, datum *d) {
	queue_head *q = (queue_head *)obj->queue;
	list *l;
	void *found = NULL;
	
	for (l = q->B; l; l = l->next)
		if (l->key == key) {
			*d = l->d;
			found = l;
			break;
		}
	
	return found;
}

static void *addL(queue_object *obj, void *_lp, int key, datum d) {
	queue_head *q = (queue_head *)obj->queue;
	list *lp = (list *)_lp, *l;
	
	if (!lp) return NULL;
	
	if (!(l = (list *)calloc(1, sizeof(list)))) return NULL;
	
	l->key = key;
	l->d = d;
	
	if (lp->prev) {
		l->next = lp;
		l->prev = lp->prev;
		lp->prev->next = l;
		lp->prev = l;
	} else {
		lp->prev = l;
		l->next = lp;
		q->B = l;
	}
	
	return l;
}

static void *addR(queue_object *obj, void *_lp, int key, datum d) {
	queue_head *q = (queue_head *)obj->queue;
	list *lp = (list *)_lp, *l;
	
	if (!lp) return NULL;
	
	if (!(l = (list *)calloc(1, sizeof(list)))) return NULL;
	
	l->key = key;
	l->d = d;
	
	if (lp->next) {
		l->next = lp->next;
		l->prev = lp;
		lp->next->prev = l;
		lp->next = l;
	} else {
		lp->next = l;
		l->prev = lp;
		q->E = l;
	}
	
	return l;
}

static void del(queue_object *obj, void *_lp) {
	queue_head *q = (queue_head *)obj->queue;
	list *lp = (list *)_lp, *l;
	
	if (!lp) return;
	else if ((q->B == lp) && (q->E == lp)) {
		q->B = q->E = NULL;
	} else if (q->B == lp) {
		q->B = lp->next;
		q->B->prev = NULL;
	} else if (q->E == lp) {
		q->E = lp->prev;
		q->E->next = NULL;
	} else {
		lp->prev->next = lp->next;
		lp->next->prev = lp->prev;
	}
	
	if (lp->d.on_delete) lp->d.on_delete(&lp->d);
	free(lp);
	
	return;
}

static void *iterB(queue_object *obj, void *_lp, int *key, datum *d, int *valid) {
	queue_head *q = (queue_head *)obj->queue;
	list *lp = (list *)_lp;
	
	*valid = 0;
	if (!lp) {
		lp = q->B;
		if (!lp) return NULL;
	}
	
	*valid = 1;
	*key = lp->key;
	*d = lp->d;
	
	return lp->next;
}

static void *iterE(queue_object *obj, void *_lp, int *key, datum *d, int *valid) {
	queue_head *q = (queue_head *)obj->queue;
	list *lp = (list *)_lp;
	
	*valid = 0;
	if (!lp) {
		lp = q->E;
		if (!lp) return NULL;
	}
	
	*valid = 1;
	*key = lp->key;
	*d = lp->d;
	
	return lp->prev;
}

