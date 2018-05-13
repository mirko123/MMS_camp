#include <stdio.h>

int counter;

void f(int num) {
	if (!num) return;
	f(num / 2);
	printf("%d", num %2);
	return;
}

int main(void) {
	int j;
	
	for (j = 1; j < 128; j++) {
		printf("%d\t", j);
		f(j);
		printf("\n");
	}
	return 0;
}
