#include <stdio.h>

void printb(unsigned int a);
unsigned int getbit(unsigned int a, int n);
void set0(unsigned int *a, int n);
void set1(unsigned int *a, int n);

int main(void) {
	unsigned int a, t0, t1;
	int j;
	
	a = 0xf00fc7c8u;
	
	printb(a);

	for (t1 = 0u, j = 31; j >= 0; j--) {
		t0 = a & 1u;
		a >>= 1;
		t1 |= (t0 << j);
	}
	
	printb(t1);
	
	return 0;
}

void printb(unsigned int a) {
	unsigned int mask;
	
	for (mask = 0x80000000u; mask; mask >>= 1)
		printf("%u", !!(a & mask));
	printf("\n");
	
	return;
}

unsigned int getbit(unsigned int a, int n) {
	return (a >> n) & 1u;
}

void set1(unsigned int *a, int n) {
	*a |= (1u << n);
	return;
}

void set0(unsigned int *a, int n) {
	*a &= ~(1u << n);
	return;
}
