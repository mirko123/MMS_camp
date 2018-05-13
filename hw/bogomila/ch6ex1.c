#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;


void ungetch(int );

int getch(void);

int getword2(char *word, int lim)
{
	int c, getch(void);
	void ungetch(int);
	char *w = word;
	int t;

	while (isspace(c = getch()))
		;
	if (c != EOF)
		*w++ = c;
	if (!isalpha(c)) {
		if (c == '\"') {
			for (c = getch(); c != '\"'; c = getch())
				;
		}
		else if (c == '#') {
			for (c = getch(); c != '\n'; c = getch())
				;
		}
		else if (c == '/')  
			if ((c = getch()) == '/') {
				for (c = getch(); c != '\n'; c = getch())
					;
			}
			else if (c == '*') {
				for (c = getch(), t = getch(); c != '*' && t != '/'; c = getch(), t = getch())
					ungetch(t);
			}
			else ungetch(c);
		else 
			for (; !isspace(c) && c != EOF; c = getch())
				;
		if (c != '\"' && c != '\n' && c != '/')
			ungetch(c);
		*w = '\0';
		return c;
	}

	for (; --lim > 0; w++)
		if (!isalnum(*w = getch())) {
			if (!isspace(*w)) {
				ungetch(*w);
				return (*w);
			}
			else {
				ungetch(*w);
				break;
			}
		}
	*w = '\0';
	return word[0];
}


int getch(void)
{
	return (bufp>0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp >= BUFSIZE) printf("too many characters\n");
	else buf[bufp++] = c;
}