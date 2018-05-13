#include <stdio.h>

int main(void) {
	unsigned int le = 0x12345678u, be;
	
	be = ((le & 0xffu) << 24) |
		((le & 0xff00u) << 8) |
		((le & 0xff0000u) >> 8) |
		((le & 0xff000000u) >> 24);
	printf("%x\n", be);

	return 0;
}
