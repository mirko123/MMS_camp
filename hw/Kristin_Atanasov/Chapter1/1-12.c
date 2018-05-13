#include <stdio.h>
#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */
/* count lines, words, and characters in input */
int main(void) {
    int c;
    while ((c = getchar()) != EOF) {
        if (c == '\n' || c == ' ' || c == '\t')
            printf("\n");
        else
            putchar(c);

    }
    return 0;
}
