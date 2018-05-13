#include <stdio.h>
#include <semaphore.h>

int main(void) {
	sem_t s;
	int j, val;
	
	sem_init(&s, 1, 2u);
	
	for (j = 0; j < 2; j++) {
		(void)sem_getvalue(&s, &val);
		printf("LOCK %d, semval = %d\n", j, val);
		sem_wait(&s);
	}

	return 0;
}
