#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

enum {
	NUM = 16,
	CYCLES = 8
};

int done = 0;
pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void *thr(void *arg) {
	long id = (long)arg;
	int j;
	
	printf("\tTHREAD START id = %ld\n", id);
	
	for (j = 0; j < CYCLES; j++) {
		printf("\t\tTHREAD id = %ld\tcycle = %d\n", id, j);
		sleep(1);
	}
	
	pthread_mutex_lock(&mtx);
	done++;
	printf("\tTHREAD END id = %ld\n", id);
	pthread_cond_signal(&cond);
	pthread_mutex_unlock(&mtx);
	
	return NULL;
}

int main(void) {
	pthread_t threads[NUM];
	int j;
	
	for (j = 0; j < NUM; j++)
		pthread_create(&threads[j], NULL, &thr, (void *)((long)j));
	
	pthread_mutex_lock(&mtx);
	
	while (done < NUM) {
		printf("done = %d\n", done);
		pthread_cond_wait(&cond, &mtx);
		printf("WAKEUP\n");
	}
	
	printf("done = %d\n", done);
	pthread_mutex_unlock(&mtx);
	
	return 0;
}
