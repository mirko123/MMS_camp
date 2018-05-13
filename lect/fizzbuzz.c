#include <stdio.h>

int main(void) {
	int j;
	
	for (j = 0; j < 100; j++)
		if (!(j % 14)) printf("%d\tFIZZBUZZ\n", j);
		else if (!(j % 2)) printf("%d\tFIZZ\n", j);
		else if (!(j % 7)) printf("%d\tBUZZ\n", j);
		else printf("%d\n", j);
	return 0;
}
