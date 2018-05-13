#include "p1.h"

void clear(unsigned int *field, int N) {
	int j;
	
	N = N / 32 + !!(N % 32);
	
	for (j = 0; j < N; j++)
		field[j] = 0u;
	
	return;
}

int get(const unsigned int *field, int N, int bit) {
	if ((bit < 0) || (bit >= N)) return -1;
	return !!(field[bit / 32] & (1u << (bit % 32)));
}

int set(unsigned int *field, int N, int bit, int boolean) {
	if ((bit < 0) || (bit >= N)) return -1;
	if (boolean) field[bit / 32] |= (1u << (bit % 32));
	else field[bit / 32] &= ~(1u << (bit % 32));
	return 0;
}

