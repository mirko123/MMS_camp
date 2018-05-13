#include <stdio.h>

#define MAXLINE 1000 // Maximum input line size
#define LIMIT 80

int getline_new(char s[], int lim);

int main() {
    // Exercise 1-17 from page 31
    // Write a program to print all input lines that are longer than 80 characters.
	int len; 			
	char line[MAXLINE]; 
	
	while ((len = getline_new(line, MAXLINE)) > 0) 
		if (len > LIMIT) 
			printf("%s", line);
	return 0;	
}

int getline_new(s, lim)
char s[];
int lim;
{
	int c, i;
	
	for (i= 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) 
		s[i] = c;
	
	
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	
	s[i] = '\0';
	return i;
}

