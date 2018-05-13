#include <stdio.h>
/* 
Write a program that prints its input one word per line.
*/

int main(void)
{
	
	int c;
	c=getchar();
	while((c=getchar()) !=EOF)
	{
		if( c==' ' || c=='\n' || c=='\t' )
		          printf("\n");
		else
		printf("%d",c);
		//putchar(c);
		c=getchar();
	}
	
	return 0;

