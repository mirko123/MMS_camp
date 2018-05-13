#include "p2.h"

void clear(unsigned char *field, int N) {
	int j;
	
	if (N % 8) N = N / 8 + 1;
	else N /= 8;
	
	for (j = 0; j < N; j++)
		field[j] = 0u;
	
	return;
}

int get(const unsigned char *field, int N, int bit) {
	if ((bit < 0) || (bit >= N)) return -1;
	return !!(field[bit / 8] & (1u << (bit % 8)));
}

int set(unsigned char *field, int N, int bit, int boolean) {
	if ((bit < 0) || (bit >= N)) return -1;
	if (boolean) field[bit / 8] |= (1u << (bit % 8));
	else field[bit / 8] &= ~(1u << (bit % 8));
	return 0;
}

