#include <stdio.h>

void f(void);

int main(void) {
	extern int global;
	
	printf("calling extern\n");
	global = 100;
	f();
	return 0;
}
