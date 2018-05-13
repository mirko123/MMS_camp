#include <stdio.h>
#include <stdlib.h>



int main() 
{
	/* Exercsise 1-6. Verify that the expression getchar() != EOF is 0 or 1. */
	int c;
	fflush(stdin);
	while ((c = getchar()) != EOF) {
		printf("%d ", c != EOF);
		putchar(c);
	}
	printf("\n%d", c != EOF);
	return 1;
}
	
