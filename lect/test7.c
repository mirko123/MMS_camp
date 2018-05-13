#include <stdio.h>

int main(void) {
	int j;
	
	for (j = 0; j < 100; j++)
		switch (j % 3) {
		case 0:
			printf("%d = 0 mod 3\n", j);
			break;
		case 1:
			printf("%d = 1 mod 3\n", j);
			break;
		default:
			printf("default %d = 2 mod 3\n", j);
		}
	
	return 0;
}
