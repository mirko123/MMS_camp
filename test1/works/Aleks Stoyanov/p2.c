#include<stdio.h>
#include<stdlib.h>

#include "p2.h"


void clear(unsigned char *t, int N)
{
	*t=0;
}

int set(unsigned char *t, int N, int bit, int boolean)
{
	if(N < 0) { printf("%s\n","Invalid range"); return 0;}
	
	*t |= (boolean & 1u) << bit;
		
	return 1;

}

int get(const unsigned char *t, int N, int bit)
{	
		unsigned char *r = t;
		return printf("%d\n",((*r >> bit) & 1u));
}



