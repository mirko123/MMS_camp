#include<stdio.h>
#include<stdlib.h>

#include "p1.h"

void printb(unsigned int a){
	unsigned int mask;
	for(mask = 0x80000000u; mask; mask >>=1)
		printf("%u", !!(a & mask));
	printf("\n");
}

void clear(unsigned int *t, int N)
{
	*t=0;
}

int set(unsigned int *t, int N, int bit, int boolean)
{
	if(N < 0) { printf("%s\n","Invalid range"); return 0;}
	
	*t |= (boolean & 1u) << bit;
		
	return 1;

}

int get(const unsigned int *t, int N, int bit)
{	
		unsigned int *r = t;
		return printf("%d\n",((*r >> bit) & 1u));
}

