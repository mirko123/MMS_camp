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
	float array[SIZE];
	int getflat(float *);

	for (n = 0; n < SIZE && getflat(&array[n]) != EOF; n++)
	{
		printf("good");
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

int getfloat(float *pt) {
	int c;
	int sign;
	float pow;

	while (isspace(c = getch()))
		;

	if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c!='.')
	{
		ungetch(c);
		return 0;
	}

	sign = (c == '-') ? -1 : 1;

	if (c == '+' || c == '-')
		c = getch();

	for (*pt = 0.0; isdigit(c); c = getch())
		*pt = 10.0 * *pt + (c - '0');
	if (c == '.')
		c = getch();

	for (pow = 1.0; isdigit(c); c = getch())
	{
		*pt = 10.0 * *pt + (c - '0');   
		pow *= 10.0;
	}

	*pt *= sign / pow;

	if (c != EOF)
		ungetch(c);

	return c;
}
