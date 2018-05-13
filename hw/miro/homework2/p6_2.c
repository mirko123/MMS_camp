// Write a program that reads a C program and prints in alphabetical 
// order each group of variable names that are identical in the first 
// 6 characters, but different somewhere thereafter. Don't count words 
// within strings and comments. Make 6 a parameter that can be set 
// from the command line. 

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <libc.h>
int getword(char *word, int lim);

int main(int argc, char *argv[]) {
	char *str = strdup("das    dasdasd ad as");
	int limit = 1000;
	int val = getword(str,limit);
	printf("%d\n", val);
	return 0;
}

int getword(char *word, int lim)
{
	int c, getch(void); 
	void ungetch(int); 
	char *w = word;
	while (isspace(c = getch()));
	
	if (c != EOF)
		*w++ = c;
	if (!isalpha(c) && c != '_') { // string constants, comments, or preprocessor control lines???
		*w = '\0';
		return c; 
	}
	for ( ; --lim > 0; w++)
		if (!isalnum(*w = getch())) {
			ungetch(*w);
			break; 
		}
	*w = '\0';
	return word[0];
}






