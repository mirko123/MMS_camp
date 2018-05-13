#include <stdlib.h>

#include "p1.h"

void clear (unsigned int *i, int N) { //set all elements to 0;

	int j;
	
	for (j = 0; j < N; j++) {
		*i &= ~(1u << j);
	} 

	return;
}

int get (const unsigned int *i, int N, int bit){
	if( bit < 0 || N <= bit) return -1;
	
	int j;
	int *temp;
	
	for( j = 0; j < N; j++){
		temp[j] = i[j];
	}
		
	return (*temp >> bit) & 1u;
}


int set(unsigned int *i, int N, int bit, int boolean){
	if( bit < 0 || N <= bit) return -1;

	if (boolean == 1)  *i |= (1u << bit);
	else if (boolean == 0) *i &= ~(1u << bit);
	else return -1;
	
	return *i;
}
