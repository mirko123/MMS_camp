// Define a macro swap(t,x,y) that interchanges 
// two arguments of type t. (Block structure will help.)
#include <stdio.h>
#include <libc.h>
#include <math.h>

#define swap(t, x, y) { t temp = x; x = y; y = temp; }
int main(int argc, char* argv[]) {
	int x = 2;
	int y = 3;

	printf("x: %d\n", x);
	printf("y: %d\n", y);

	swap(int,x,y);
	printf("after \n");
	printf("x: %d\n", x);
	printf("y: %d\n", y);
	
	return 0;
}

