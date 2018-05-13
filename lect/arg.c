#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int vararg(int n, ...) {
	va_list v;
	int s = 0, j;
	
	va_start(v, n);
	for (j = 0; j < n; j++)
		s += va_arg(v, int);
	va_end(v);
	
	return s;
}

int main(void) {
	printf("%d\n", vararg(3, 1, 2, 3));
	printf("%d\n", vararg(5, 1, 2, 3, 4, 5));
	printf("%d\n", vararg(2, 2, 3, 10));
	printf("%d\n", vararg(2, 10, 15));
	return 0;
}
