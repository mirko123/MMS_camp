#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#include "queue.h"

enum {
	N = 10240,
	WORKERS = 4
};

double c[N][N], a[N][N], b[N][N];

void *worker(void *arg) {
	queue_object *q = (queue_object *)arg;
	datum d;
	double sum;
	int j, k;
	
	while (q->getB(q, NULL, &d)) {
		printf("%d\n", d.data.i);
		for (j = 0; j < N; j++) {
			sum = 0.0;
			for (k = 0; k < N; k++)
				sum += a[d.data.i][k] * b[k][j];
			c[d.data.i][j] = sum;
		}
	}
	
	return NULL;
}

int main(void) {
	queue_object *q;
	pthread_t thr[WORKERS];
	pthread_attr_t ta;
	datum d;
	int j;
	
	q = queue_create();
	
	for (d.type = INT, d.data.i = 0; d.data.i < N; d.data.i++)
		q->addE(q, 0, d);
	
	pthread_attr_init(&ta);
	
	for (j = 0; j < WORKERS; j++)
		pthread_create(&thr[j], &ta, &worker, q);
	
	for (j = 0; j < WORKERS; j++)
		pthread_join(thr[j], NULL);
	
	queue_delete(q);
	
	return 0;
}
