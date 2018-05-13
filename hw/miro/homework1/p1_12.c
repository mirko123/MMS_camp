#include <stdio.h>

int main(void) {
	char c;
	int counter  = 0;
	while((c = getchar()) != '\n') {
		if(c == ' ' && counter == 0) {
			printf("\n");
		}
		else {
			printf("%c", c);
			counter = 0;
		}
	}
	return 0;
}
