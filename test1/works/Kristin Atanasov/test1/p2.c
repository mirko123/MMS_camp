#include <stdlib.h>
#include "p2.h"

void clear(unsigned char *ptr, int N) {

	ptr = (unsigned char*)calloc(N);

	*ptr = (*ptr & 0);

	return;
}
int get(const unsigned char *ptr, int N, int bit){
	
	int found;
	if (bit > (sizeof(N)*8)){
		printf("Range Error");
		return -1;
	}

	ptr = (unsigned char*)calloc(N);
	found = (*ptr >> bit) & 1u;
	
	return found;

}
int set(unsigned char *ptr, int N, int bit, int boolean){

	ptr = (unsigned char*)calloc(N);
	boolean = !!boolean;
	if (bit > (sizeof(N)*8)){
		printf("Range Error");
		return -1;
	}
	*ptr ^= (-(unsigned char)boolean ^ *ptr) & (1u << bit);

	return *ptr;
}
