#include <stdio.h>
#include <stdlib.h>

#include "p1.h"

enum {
	N = 256
};

int main(void) {
	unsigned int *s;
	int j, k;
	
	s = (unsigned int *)malloc((N / 32 + !!(N % 32)) * sizeof (*s));
	
	clear(s, N);
	set(s, N, 0, 0);
	set(s, N, 1, 0);
	
	for (j = 2; j < N; j++)
		if (!get(s, N, j))
			for (k = 2; (k * j) < N; k++)
				set(s, N, k * j, 1);
	
	for (j = 0; j < N; j++)
		printf("%d\t%d\n", j, get(s, N, j));
	
	free(s);
	return 0;
}

