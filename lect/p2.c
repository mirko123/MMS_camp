#include <stdio.h>

int global;

void f(void) {
	printf("extern call, global = %d\n", global);
	return;
}
