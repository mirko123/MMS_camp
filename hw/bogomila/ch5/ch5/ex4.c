#include<stdio.h>
#include<string.h>

int strend(char *s, char *t)
{
	int length;
	length = strlen(t);
	while (*s != '\0')
		++s;
	--s;

	while (*t != '\0')
		++t;
	--t;
	while (length > 0)
	{
		if (*t-- == *s--) length--;
		else return 0;
	}
	if (length == 0)
		return 1;
}