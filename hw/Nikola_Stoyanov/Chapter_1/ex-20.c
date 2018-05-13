#include<stdio.h>

#define TABLEN 8

int main(void)
{
    // Exercise 1-20. Write a program detab that replaces tabs in the input 
    // with the proper number of blanks to space to the next tab stop. 
    // Assume a fixed set of tab stops, say every n columns. 
    // Should n be a variable or a symbolic parameter? 
    int num_of_spaces, pos, c;
    
    num_of_spaces = 0;
    pos = 0;
    
    while ((c=getchar()) != EOF) {
        if ( c == '\t') {
            num_of_spaces = TABLEN - (pos % TABLEN);
    
            while( num_of_spaces > 0) {
                putchar(' ');
                ++pos;
                --num_of_spaces;
            }
        } else if ( c == '\n') {
            putchar(c);
            pos = 0;
        } else {
            putchar(c);
            ++pos;
        }
    }
    return 0;
}




