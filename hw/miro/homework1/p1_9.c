#include <stdio.h>

int main(void) {
	char c;
	int counter = 0;
	int blankCounter = 0;
	const int max = 64;
	char arr[max + 1];
	while((c = getchar()) != '\n' && counter < max - 3) {
		if(c == ' ') {
			blankCounter++;
		}
		else if(blankCounter != 0) {
			arr[counter] = ' ';
			arr[counter + 1] = c;
			counter += 2;
			blankCounter = 0;
		}
		else {
			arr[counter] = c;
			counter++;
		}

	}
	arr[counter] = '\0';
	printf("%s\n", arr);

	return 0;
}