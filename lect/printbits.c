#include <stdio.h>

int main(void) {
	unsigned int mask;
	int a;
	
	for (a = -10; a < 11; a++) {
		printf("%d\t", a);
		for (mask = 0x80000000u; mask; mask >>= 1)
			printf("%u", !!((unsigned int)a & mask));
		printf("\n");
	}
	
	return 0;
}
