#include <stdio.h>

struct test {
	int i1;
	long l1;
	char c1;
	short s1;
};
typedef struct test test;

int main(void) {
	test t;
	
	printf("%lu\n", sizeof (t));

	printf("%p\n", &t);
	printf("%p\n", &t.i1);
	printf("%p\n", &t.l1);
	printf("%p\n", &t.c1);
	printf("%p\n", &t.s1);

	return 0;
}
