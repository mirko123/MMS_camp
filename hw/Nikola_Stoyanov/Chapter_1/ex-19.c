
#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size */

int getline_new(char s[], int lim);
int reverseline(char line[], char reversed_line[]);

int main()
{
    // Exercise 1-19. Write a function reverse(s) that reverses the character string s.
    // Use it to write a program that reverses its input a line at a time. 
    int len; /* current line length */
    char line[MAXLINE]; /* current input line */
    char reversed_line[MAXLINE];
    
    while ((len = getline_new(line, MAXLINE)) > 0)
        if(reverseline(line, reversed_line))
            printf("%s", reversed_line);;
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

int reverseline(char line[], char reversed_line[])
{
    int len, i;
    
    if (!line) return 0;
    
    len = 0;
    while(line[len]) 
        ++len;
        
    if (line[--len] == '\n') --len;

    for (i = 0; i <= len; i++) 
        reversed_line[i] = line[len - i];
    
    reversed_line[i] = '\0';
    
    return 1;
}



