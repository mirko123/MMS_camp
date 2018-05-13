// Write a recursive version of the function reverse(s), 
// which reverses the string s in place. 

#include <stdio.h>
#include <libc.h>
#include <math.h>

void reverse(char *str) {
	int length = strlen(str);
	char temp;
	int i;
	for (i = 0; i < length/2; ++i) {
		temp = str[i];
		str[i] = str[length - i - 1];
		str[length - i - 1] = temp;
	}
}

int main(int argc, char* argv[]) {
	char *str = strdup("0123456789");
	reverse(str);
	printf("%s\n", str);

	return 0;
}

