#include <stdio.h>

#include "p1.h"

int main(void) {
	unsigned int a[5];
	int i = 0, j;
	
	clear(a, 160);
	
	for (j = -1; j < 161; j++)
		printf("%d\n", get(a, 160, j));
	
	for (j = -1; j < 161; j++)
		printf("%d\n", set(a, 160, j, (i++) % 2));

	for (j = -1; j < 161; j++)
		printf("%d\n", get(a, 160, j));
	
	return 0;
}

