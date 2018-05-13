#include <stdlib.h>

#include "p2.h"
#include "p3.h"

enum {
	M = 17,
	N = 17
};

int main(void) {
	unsigned char *d;
	int i, j;
	
	d = (unsigned char *)malloc((M * N) / 8 + !!((M * N) % 8));
	if (!d) return 1;
	clear(d, M * N);
	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++)
			if (
				(j == i) ||
				(j == (N - i - 1)) ||
				(j == 0) ||
				(j == (N - 1)) ||
				(i == 0) ||
				(i == (N - 1))
			) setpix(d, M, N, j, i, 1);
			else setpix(d, M, N, j, i, 0);
	}
	display(d, M, N);
	free(d);
	return 0;
}
