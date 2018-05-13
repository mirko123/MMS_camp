#include <stdio.h>

char lower(char c);

int main(void) {
    char c;
    while ((c = getchar()) != EOF) {
        putchar(lower(c));
    }
}
char lower(char c) {
    return 'A' <= c && c <= 'Z' ? c - 'A' + 'a' : c;
}
