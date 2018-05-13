#ifndef _LIST_H_
#define _LIST_H_

struct list {
	int key;
	datum d;
	struct list *prev, *next;
};
typedef struct list list;

struct queue_head {
	list *B, *E;
};
typedef struct queue_head queue_head;

#endif
