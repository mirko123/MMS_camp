#include <stdio.h>
#include <stdlib.h>

void main() 
{
	// Exercise 1-8. Write a program to count blanks, tabs, and newlines. 
	int c, newlines = 0, blanks = 0, tabs = 0;
	while ((c = getchar()) != EOF)
        if (c == '\n')
            ++newlines;
        else if (c == ' ')
            ++blanks;
        else if (c == '\t')
            ++tabs;
    printf("newlines = %d blanks = %d tabs = %d", newlines, blanks, tabs);
	return;
}
