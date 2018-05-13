#include <stdio.h>
#define BUFFSIZE 100
void strcatdos(char *s, char *t);

int main(void) {
    char s[BUFFSIZE] = "str";
    char t[] = "cat works apparently";

    strcatdos(s, t);

    printf("printf -> %s\n", s);

    return 0;
}
void strcatdos(char *s, char *t) {
    while (*s)
        *s++;
    while (*s++ = *t++)
        ;

    return;
}

