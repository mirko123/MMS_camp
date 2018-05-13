#include<stdio.h>
#include<string.h>

void strcpy2(char *s, char* t, int n) {

		while (*t && n-- > 0)
			*s++ = *t++;

		int more = strlen(s) - n;

		while (more-- > 0) {
			*s++;
		}

		*s = '\0';
}

void strncat2(char *str1, char *str2, char *result, int n) {
	while (*str1) {
		*result++ = *str1++;
	}

	while (n-- >0) {
		*result++ = *str2++;
	}

	*result = '\0';
}

int strncmp2(char *s, char *t, int n)
{
	for (; *s == *t; s++, t++)
		if (*s == '\0' || --n <= 0)
			return 0;
	return *s - *t;

}