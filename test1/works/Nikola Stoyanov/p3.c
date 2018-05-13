
#include <stdio.h>
#include <stdlib.h>


#include "p2.h"
#include "p3.h"


void display(const unsigned char *matrix, int M, int N) {
	int i, j,pix = 0;
	for (i = 0; i < 8; i++) {
		printf("\n");
		for (j = 0; j < 8; j++) {
			pix = getpix(matrix, M, N, i, j);
			if (pix == 0)
				printf(".");
			else printf("#");
		}	
	}
}

int getpix( const unsigned char *matrix, int M, int N, int X, int Y) {
	int returned_bit;
	
	returned_bit = get(&matrix[Y], N, X);
	if( returned_bit == -1) fprintf(stderr, "Range error\n");

	return returned_bit;

}

int setpix(unsigned char *matrix, int M, int N, int X, int Y, int colour) {
	int returned_bit;
	returned_bit = set(&matrix[Y], N, X, colour);
	if( returned_bit == -1) fprintf(stderr, "Range error\n");
	return 1;
}








