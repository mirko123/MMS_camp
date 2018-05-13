
#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size */

int getline_new(char s[], int lim);
int trimend(char s[]);

int main()
{
    // Exercise 1-18. Write a program to remove trailing blanks and tabs from 
    // each line of input, and to delete entirely blank lines. 
    int len; /* current line length */
    char line[MAXLINE]; /* current input line */
    
    while ((len = getline_new(line, MAXLINE)) > 0)
        if(trimend(line) > 0)
            printf("%s",line);
    return 0;
}

int getline_new(char s[], int lim)
{
    int c, i;
    
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return(i);
}

int trimend(char s[])
{
    int i;
    
    i = 0;
    while(s[i] != '\0')
        i++;
    
    for(--i ; ((s[i] == ' ') || (s[i] == '\t')); i--)
        ;
    
    if (i > 0)
        s[++i] = '\0';
    
    return i;
}



