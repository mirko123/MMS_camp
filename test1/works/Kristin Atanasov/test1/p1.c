#include <stdlib.h>
#include "p1.h"

void clear(unsigned int *ptr, int N) {

	ptr = (unsigned int*)calloc(N);

	*ptr = (*ptr & 0);

	return;
}
int get(const unsigned int *ptr, int N, int bit){
	
	int found;
	if (bit > (sizeof(N)*8)){
		printf("Range Error");
		return -1;
	}

	ptr = (unsigned int*)calloc(N);
	found = (*ptr >> bit) & 1u;
	
	return found;

}
int set(unsigned int *ptr, int N, int bit, int boolean){

	ptr = (unsigned int*)calloc(N);
	boolean = !!boolean;
	if (bit > (sizeof(N)*8)){
		printf("Range Error");
		return -1;
	}
	*ptr ^= (-(unsigned int)boolean ^ *ptr) & (1u << bit);

	return *ptr;
}



