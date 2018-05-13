#include <stdlib.h>

static void *search(queue_object *obj, int key, datum *d);

void calc(FILE *in, FILE *out, queue_object *q);

queue_object *queue_create(void) {
	queue_object *obj;
	queue_head *q;
	

if (!(obj = (queue_object *)calloc(1, sizeof (*obj)))) goto bad0;
	if (!(q = (queue_head *)calloc(1, sizeof(*q)))) goto bad1;



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


