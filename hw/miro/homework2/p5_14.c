// Modify the sort program to handle a -r flag, which indicates 
// sorting in reverse (decreasing) order. Be sure that -r works with -n. 
#include <stdio.h>
#include <stdlib.h>
int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int cmpfuncDEC (const void * a, const void * b) {
   return ( *(int*)b - *(int*)a );
}

int main(int argc, char *argv[]) {
	int values[] = { 88, 56, 100, 2, 25 };
    int size = sizeof(values) / sizeof(values[0]);
	int i;

	if(argc == 1) {
		printf("arguments = 0\n");
		return 0;
	}

	if(argv[1][1] == 'r') {
		qsort(values, size, sizeof(int), cmpfunc);
	}
	else {
		qsort(values, size, sizeof(int), cmpfuncDEC);
	}

	printf("After: \n");
	for( i = 0 ; i < size; i++ ) {   
		printf("%d ", values[i]);
	}
	printf("\n");
	return 0;
}








