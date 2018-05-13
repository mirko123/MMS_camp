#include <stdio.h>

void f(void) {
	static int j = 0;
	
	printf("%d\n", j);
	j++;
	
	return;
}

int main(void) {
	int j;

	for (j = 0; j < 10; j++)
		f();
	
	return 0;
}
