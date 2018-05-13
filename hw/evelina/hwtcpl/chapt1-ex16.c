#include <stdio.h>
/*
Revise the main routine of the longest-line program so it will correctly print the
length of arbitrary long input lines, and as much as possible of the text.
*/
#define MAXLINE 1000 

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

int main(void)
{
    int len;
    int max;
    char line[MAXLINE]; 
    char longest[MAXLINE];
    max = 0;
    while ((len = get_line(line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    if (max > 0) {
        printf("longest line:\n");
        printf("%s\n", longest);
        printf("The length of it is %d.\n", max);
    }   

    return 0;
}

int get_line(char s[], int lim)
{
    int c, i, l;

    for (i = 0, l = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
        if (i < lim - 1)
            s[l++] = c;
    }
    if (c == '\n') {
        if (l < lim - 1)
            s[l++] = c;
        ++i;
    }   
    s[l] = '\0';

    return i;
}

void copy(char to[], char from[])
{
    int i=0;
    while ((to[i] = from[i]) != '\0')
	{
		++i;
	}
}