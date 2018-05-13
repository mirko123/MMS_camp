#include <stdio.h>
#include <stdlib.h>

#include "p2.h"


void clear (unsigned char *px, int N) {
	//if (bit > N) return -1;
	*px = 0;
}
int get(const unsigned char *px, int N, int bit) {
	int returned_bit;
	if (bit > N) return -1;	

	returned_bit = (*px >> bit) & 1u;

	return returned_bit;
}
int set(unsigned char *px, int N, int bit, int boolean) {
	
	
	if (bit > N) return -1;	
	
	*px |= (boolean & 1u) << bit;
	return 1;
}

