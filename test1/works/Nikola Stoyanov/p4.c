#include <stdio.h>
#include <stdlib.h>


#include "p2.h"
#include "p3.h"


int main() {
	int i, j;
	int returned_bit = 0;
	int N = 8;
	int M = 8;
	unsigned char *matrix = (unsigned char *)malloc(M*N);
	int xPixel[8][8] = {
	1,1,1,1,1,1,1,1,
	1,1,0,0,0,0,1,1,
	1,0,1,0,0,1,0,1,
	1,0,0,1,1,0,0,1,
	1,0,0,1,1,0,0,1,
	1,0,1,0,0,1,0,1,
	1,1,0,0,0,0,1,1,
	1,1,1,1,1,1,1,1,
	};
	for (i = 0; i < M; i++) {
		for (j = 0; j < 10; j++) {
			setpix(matrix, M, N, j, i, xPixel[i][j]);
		}	
	}

	display(matrix, M, N);

	printf("\n");
	return 0;
}





