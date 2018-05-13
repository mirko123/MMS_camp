#include<stdio.h>
#include<string.h>

#define MAXLINES 5000 
#define MAXLEN 1000 
#define MAXSTOR 5000

char *lineptr[MAXLINES];
char linestor[MAXLINES];

int getline2(char *s, int lim)
{
	int c;
	char *t;
	t = s;

	while (--lim >0 && (c = getchar()) != EOF && c != '\n')
		*s++ = c;
	if (c == '\n')
		*s++ = c;

	*s = '\0';

	return s - t;
}

int readlines(char *lineptr[], char *linestor, int maxlines)
{
	int len;
	int nlines;
	char line[MAXLEN];
	char *p = linestor;
	char *linestop = linestor + MAXSTOR;

	nlines = 0;

	while ((len = getline2(line, MAXLEN)) > 0)
		if (nlines >= maxlines || p + len > linestop)
			return -1;
		else
		{
			line[len - 1] = '\0';
			strcpy(p, line);
			lineptr[nlines++] = p;
			p += len;
		}
	return nlines;
}


