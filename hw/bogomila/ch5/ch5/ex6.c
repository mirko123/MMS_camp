#include<stdio.h>
#include<string.h>

int main(void) {
	char s[] = "hey";
	reverse(s);
}
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

int atoi(char *s) {
	int n;

	for (; *s >= '0' && *s <= '9';s++) {
		n = 10 * n + (*s - '0');
	}

	return n;
}

void reverse(char *s) {
	int c;
	int length;
	length = strlen(s);

	for (; *s && length > 0; s++, length--) {
		c = *s;
		*s = *(s + length);
		*(s + length) = c;
	}
}