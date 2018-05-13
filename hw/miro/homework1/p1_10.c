#include <stdio.h>

int main(void) {
	char c;
	while((c = getchar()) != '\n') {
		if(c == '\t') {
			printf("\\t");
		}
		else if(c == '\b') {
			printf("\\b");
		}
		else {
			printf("%c", c);
		}
	}
	printf("\n");
	return 0;
}