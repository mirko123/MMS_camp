#include<stdio.h>
#include<ctype.h>

#define BUFSIZE 100
#define SIZE 100


char buf[BUFSIZE];
int bufp = 0;

int getch(void);
void ungetch(int);

int main(void) {

	int n;
	int array[SIZE];
	int getint(int *);

	for (n = 0; n<SIZE && getint(&array[n]) != EOF; n++) {
		printf("storing in n = %d, getint %d\n", n, array[n]);
	}

	return 0;
}

int getch(void) {
	return (bufp < BUFSIZE) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
	if (bufp > BUFSIZE) printf("too many characters\n");
	else buf[bufp++] = c;
}

int getint(int *pt) {
	int c;
	int sign;

	while (isspace(c = getch()))
		;

	if (!isdigit(c) && c != EOF && c != '+' && c != '-')
	{
		ungetch(c); 
		return 0;
	}

	sign = (c == '-') ? -1 : 1;

	if (c == '+' || c == '-')
		c = getch();

	for (*pt = 0; isdigit(c); c = getch())
		*pt = 10 * *pt + (c - '0');

	*pt *= sign;

	if (c != EOF)
		ungetch(c);

	return c;
}
