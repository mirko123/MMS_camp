#include <stdlib.h>
#include <string.h>

#include "p3.h"

void clear (unsigned char *c, int N) { //set all elements to 0;

	int j;
	
	for (j = 0u; j < N; j++) {
		free(c[j]);
	} 
	return;
}

int get (const unsigned char *c, int N, int bit){
	if( bit < 0u || N <= bit) return -1;
		
	char *c2 = (char *) calloc (N, sizeof(char));
	char returned_value;
	
	c2 = strdup(c);
	
	returned_value = (*c2 >> bit) & 1u;
	
	clear(&c2, N);
	
	return returned_value;
}


int set(unsigned char *c, int N, int bit, int boolean){
	if( bit < 0u || N <= bit) return -1;

	if (boolean == 1u)  *c |= (1u << bit);
	else if (boolean == 0u) *c &= ~(1u << bit);
	else return -1;
	
	return *c;
}
