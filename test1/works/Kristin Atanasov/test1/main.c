#include <stdio.h>
#include <stdlib.h>
#include "p1.h"

int main(void){

	const unsigned int x = 4000;
	unsigned int *p;
	//p = &x;
	int N = sizeof(int);

	*p = get(x, N, 4);
	printf("%u\n", x);

	return 0;
}
