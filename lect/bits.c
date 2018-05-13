#include <stdio.h>

int main(void) {
	int a = -1, b = 1;
	
	printf("%d %d\n", a >> 1, a / 2);
	printf("%d %d\n", b >> 1, b / 2);

	printf("%d\n", ~a);
	printf("%d\n", ~b);
	
	printf("%d\n", b & 0x80000000);
	printf("%d\n", b | 0x80000000);
	
	printf("%d\n", a & 0x80000000);
	printf("%d\n", a | 0x80000000);
	
	return 0;
}
