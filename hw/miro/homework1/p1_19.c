// Write a function reverse(s) that reverses the character string s. 
// Use it to write a program that reverses its input a line at a time. 

 // Revise the main routine of the longest-line program so it will correctly 
 // print the length of arbitrary long input lines, and as much as possible of the text. 

#include <stdio.h>
#include <libc.h>

void reverse(char *str);

int main(void) {
	char *str = strdup("1234567890");

	printf("%s\n", str);
	reverse(str);
	printf("%s\n", str);
	return 0;
}

void reverse(char *str) {
	int len = strlen(str);
	int i;
	char symbol;
	for (i = 0; i < len/2; ++i)
	{
		symbol = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = symbol;
	}
}









