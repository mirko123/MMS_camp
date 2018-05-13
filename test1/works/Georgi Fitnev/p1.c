#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "p1.h"

void clear(unsigned int * i, int N)
{
 	int j = 0;
	for(j = 0; j<N; j++)
	{
	set(i, N, j , 0);
	}

}

int get(const unsigned int *i, int N, int bit)
{
	
      int j;
	unsigned int * temp;
	for(j = 0; j< N; j++)
	{
	*(temp + j) = *(i+j);
	}

	return (*temp >> bit) & 1u;

}

int set(unsigned int * i, int N , int bit, int boolean)
{
	if(bit>N) return -1;
	if(N<0)
	{
	return -1;
	return 0; 
	}

	if(boolean == 0)
	{
	*i &= (1u <<bit);
	}

	else if(boolean == 1)
	{
	*i |= (1u <<bit);
	}

	else return -1;	


}
int main(void)
{
return 0;
}


