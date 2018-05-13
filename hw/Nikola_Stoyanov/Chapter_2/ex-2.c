
#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size */

char line[MAXLINE]; /* input line */


int main() /* find longest line; specialized version */
{
    int i;
    char c;
    
    // Exercise 2-2. Write a loop equivalent to the for loop above without using && or ||.
    for (i = 0; (c = getchar()) != EOF; ++i) {
        line[i] = c;
        if ( c == '\n') break;
        if (!(i < MAXLINE - 1)) break;
       
    }
    i = 0;
    while (line[i]) {
        printf("%c", line[i++]);
    }
    return 0;
}


