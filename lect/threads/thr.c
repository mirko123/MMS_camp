#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#include "queue.h"

pthread_barrier_t bar;

void *thr0(void *arg) {
	queue_object *q = (queue_object *)arg;
	datum d;
	
	for (d.type = INT, d.data.i = 0; ; d.data.i++) {
		q->addE(q, 0, d);
		if (!(d.data.i % 8)) {
			sleep(1);
			pthread_barrier_wait(&bar);
		}
	}
	
	return NULL;
}

void *thr1(void *arg) {
	queue_object *q = (queue_object *)arg;
	datum d;
	
	while (1) {
		pthread_barrier_wait(&bar);
		while (q->getB(q, NULL, &d))
			printf("%d\n", d.data.i);
	}
	
	return NULL;
}

int main(void) {
	pthread_t t0, t1;
	pthread_attr_t ta0, ta1;
	long rv0, rv1;
	queue_object *q;
	
	q = queue_create();
	
	pthread_barrier_init(&bar, NULL, 2u);
	
	pthread_attr_init(&ta0);
	pthread_attr_init(&ta1);
	
	pthread_create(&t0, &ta0, &thr0, q);
	pthread_create(&t1, &ta1, &thr1, q);
	
	pthread_join(t0, (void **)&rv0);
	pthread_join(t1, (void **)&rv1);
	
	pthread_barrier_destroy(&bar);
	
	printf("rv0 = %ld, rv1 = %ld\n", rv0, rv1);
	
	return 0;
}
