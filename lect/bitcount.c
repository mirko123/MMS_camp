#include <stdio.h>

void printb(unsigned int a);
unsigned int getbit(unsigned int a, int n);
void set0(unsigned int *a, int n);
void set1(unsigned int *a, int n);

int main(void) {
	unsigned int a, t;
	int j;
	
	a = 0xf00fc7c8u;
	printb(a);
	
	for (t = 0u, j = 0; j < 32; j += 2)
		t += getbit(a, j);
	printf("%u\n", t);
	
	for (t = 0u, j = 1; j < 32; j += 2)
		t += getbit(a, j);
	printf("%u\n", t);
	
	for (t = 0u, j = 0; j < 32; j++)
		t += getbit(a, j);
	printf("%u\n", t);
	
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
