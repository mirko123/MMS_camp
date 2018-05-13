#include <stdio.h>

int main() /* count lines, words, chars in input */
{
    //Exercise 1-12. Write a program that prints its input one word per line. 
    unsigned char c;
    
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t')
            putchar('\n');
        else 
            putchar(c);
    }
    return 1;
}

