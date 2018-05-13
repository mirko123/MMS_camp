#include <stdio.h>

int main(void) {
	unsigned int a;
	
	for (a = 0u; a < 11u; a++)
		printf("%u\t%d\n", a, (int)(~a + 1u));
	
	return 0;
}
