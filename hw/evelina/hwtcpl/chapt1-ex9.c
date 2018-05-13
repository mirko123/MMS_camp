#include <stdio.h>
/*Write a program to copy its input to its output, replacing each string of one or
more blanks by a single blank. */

int main()
{
	
	int c, blanks;
    blanks= 0;
    while ((c = getchar()) != EOF)
        if (c == ' ') {
            if (!blanks) {
                blanks = 1;
                putchar(c);
            }
        } else {
            blanks = 0;
            putchar(c);
        }

	
	/*
	int c;	
	while ((c=getchar()) != EOF)
	{
		if(c==' ') 
		{
		putchar(c);
		while((c=getchar())!=EOF && c==' ');
		}
		
		if(c!= EOF) putchar(c); */
	return 0;
	}
}

