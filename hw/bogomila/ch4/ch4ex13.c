#include<stdio.h>
#include<string.h>

#define MAX 100

int getline(char*, int );
void reverse(char*);

int main(void)
{
	char s[MAX];

	getline(s, MAX);

	reverse(s);

	printf("%s", s);

	return 0;
}

int getline(char s[], int lim)
{
	int i, c;

	for (i = 0; i<lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;

	if (c == '\n')
		s[i++] = '\n';

	s[i] = '\0';
}

void reverser(char s[], int i, int len)
{
	int c, j;

	j = len - (i + 1);

	if (i < j)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;

		reverser(s, ++i, len);
	}
}

void reverse(char s[])
{
	reverser(s, 0, strlen(s));
}

