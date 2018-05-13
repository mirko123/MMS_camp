#include <stdio.h>
#include <stdlib.h>

#include "p1.h"



int main() {
	int i;
	int returned_bit = 0;
	unsigned int x;
	unsigned int *px;
	int N = 32;
	int j ;

	px =  &x;
	for (i = 0; i < 32; i++) {
	j = i % 2;
	set(px, N, i, j);
	}
	//clear(px, N);
	printf("\n");
	for (i = 0; i < 32; i++) {
		
	
	returned_bit = get( px, N, i);
	printf("%d", returned_bit);
	}
	printf("\n");
	return 0;
}


void clear (unsigned int *px, int N) {
	//if (bit > N) return -1;
	*px = 0;
}
int get(const unsigned int *px, int N, int bit) {
	int returned_bit;
	if (bit > N) return -1;	

	returned_bit = (*px >> bit) & 1u;

	return returned_bit;
}
int set(unsigned int *px, int N, int bit, int boolean) {
	
	
	if (bit > N) return -1;	
	
	*px |= (boolean & 1u) << bit;
	return 1;
}

