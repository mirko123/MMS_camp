#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	//Exercise 1-10. Write a program to copy its input to its output, replacing each tab by \t,
	//each backspace by \b, and each backslash by \\. This makes tabs and backspaces visible in
	//an unambiguous way. 
    unsigned char c;
    
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            putchar('\\');
            putchar('t');
        } else if (c == '\b') {
            putchar('\\');
            putchar('b');
        } else if (c == '\\') {
            putchar('\\');
            putchar('\\');
        } else 
            putchar(c);
    }
    
    return 1;
}

