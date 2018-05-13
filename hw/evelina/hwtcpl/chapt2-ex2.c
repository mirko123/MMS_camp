#include <stdio.h>

/*
Write a loop equivalent to the for loop above without using && or ||.
	for (i=0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
	s[i] = c;
*/

int main(void)
{

	int i,lim,c;
	i=0;
	lim=100;
	char s[lim];
	
	while (i < lim-1)
	{
		c = getchar();

		if (c == EOF)
			break;
		else if (c == '\n')
			break;

		s[i++] = c;
	}

	s[i] = '\0'; 

	for (int j=0;j<i;j++) printf("%c \n", s[i]);
	return;
}