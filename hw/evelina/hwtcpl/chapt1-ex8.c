#include <stdio.h>
//Write a program to count blanks, tabs, and newlines.
int main()
{
	int b,t,n;
	b=0;
	t=0;
	n=0;
	int c;
	while (getchar() != EOF)
	{
	if(c == '\n') n++;
	if (c == '\t') t++;
	if (c == ' ')  b++;
	}
		printf("%d \t %d \t %d \n", b , t ,n);
	
	return 0;
}