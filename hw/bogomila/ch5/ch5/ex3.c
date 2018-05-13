#include<stdio.h>

void strcat2(char *s, char *t) {
	  
	while (*s != '\0')
		s++;
	s--;

	while ((*s++ = *t++))
		;

}