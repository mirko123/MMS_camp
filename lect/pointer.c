#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int a[10], *b;
	
	b = a;
	printf("%p\n", b);
	*(b + 1000) = 5;
	printf("%d\n", a[3]);
	printf("%lu %lu %lu\n", sizeof (int), sizeof (long), sizeof (b));
	printf("%lu %lu\n", sizeof (a), sizeof (a) / sizeof (a[0]));
	
	printf("%p %p\n", a, a + 1);
	
	*((int *)843753658l) = 0;
	
	return 0;
}
