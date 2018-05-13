#ifndef _LIST_H_
#define _LIST_H_

#include <pthread.h>

struct list {
	int key;
	datum d;
	struct list *prev, *next;
};
typedef struct list list;

struct queue_head {
	pthread_mutex_t qmtx;
	list *B, *E;
};
typedef struct queue_head queue_head;

#endif
