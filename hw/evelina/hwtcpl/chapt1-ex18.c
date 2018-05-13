#include <stdio.h>
#define MAXLINE 1000
/*
Write a program to remove trailing blanks and tabs from each line of input, and
to delete entirely blank lines.
*/


int get_line(char s[], int lim)
{
    int c, i, l;

    for (i = 0, l = 0; (c = getchar()) != EOF && c != '\n'; ++i)
        if (i < lim - 1)
            s[l++] = c;
    if (c == '\n' && l < lim - 1)
        s[l++] = c;
    s[l] = '\0';

    return l;
}

int main(void)
{
    int len; /* current line length */
    char line[MAXLINE]; /* current input line */

    while ((len = get_line(line, MAXLINE)) > 0) {
        if (len == 1 && line[0] == '\n')
            continue;
        printf("%s\n", line);
    }

    return 0;
}