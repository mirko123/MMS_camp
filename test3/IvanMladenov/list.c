#include <stdlib.h>

#include "list.h"

void init_queue(queue *q) {
	q->B = q->E = NULL;
	return;
}

void del_queue(queue *q) {
	list *l, *t;
	
	l = q->B;
	
	while (l) {
		t = l;
		l = l->next;
		free(t);
	}
	
	init_queue(q);
	
	return;
}

int addB(queue *q, int key, datum d) {
	list *l;
	
	l = (list *)calloc(1, sizeof(list));
	if (!l) return 0;
	
	l->key = key;
	l->d = d;
	
	if (q->B) {
		l->next = q->B;
		q->B->prev = l;
		q->B = l;
	} else q->B = q->E = l;
	
	return 1;
}

int addE(queue *q, int key, datum d) {
	list *l;
	
	l = (list *)calloc(1, sizeof(list));
	if (!l) return 0;
	
	l->key = key;
	l->d = d;
	
	if (q->E) {
		l->prev = q->E;
		q->E->next = l;
		q->E = l;
	} else q->B = q->E = l;
	
	return 1;
}

int getB(queue *q, int *key, datum *d) {
	list *l;
	
	if (!q->B) return 0;
	
	l = q->B;
	if (l->next) {
		q->B = l->next;
		q->B->prev = NULL;
	} else init_queue(q);
	
	*key = l->key;
	*d = l->d;
	
	free(l);
	
	return 1;
}

int getE(queue *q, int *key, datum *d) {
	list *l;
	
	if (!q->E) return 0;
	
	l = q->E;
	if (l->prev) {
		q->E = l->prev;
		q->E->next = NULL;
	} else init_queue(q);
	
	*key = l->key;
	*d = l->d;
	
	free(l);
	
	return 1;
}

void *search(queue *q, int key, datum *d) {
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

void *addL(queue *q, void *_lp, int key, datum d) {
	list *lp = (list *)_lp, *l;
	
	if (!lp) return NULL;
	
	l = (list *)calloc(1, sizeof(list));
	if (!l) return NULL;
	
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

void *addR(queue *q, void *_lp, int key, datum d) {
	list *lp = (list *)_lp, *l;
	
	if (!lp) return NULL;
	
	l = (list *)calloc(1, sizeof(list));
	if (!l) return NULL;
	
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

