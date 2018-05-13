#include<stdio.h>
#include<stdlib.h>
#include "p1.h"

int main() {
	return 0;
}

void clear(unsigned int *p, int N){
	int i;

	for( i = 0; i < N; i++){
	*p &= ~(1u << i);
	}
}
int get(const unsigned int *p, int N, int bit){
	if(bit > N) return -1;
	
	return (*p >> bit) & 1u;
}
int set(unsigned int *p, int N, int bit, int boolean){
	if(bit > N) return -1;

	if(boolean == 1)
	*p |= (1u << bit);
	else
	*p &= ~(1u << bit);

	return;
}
