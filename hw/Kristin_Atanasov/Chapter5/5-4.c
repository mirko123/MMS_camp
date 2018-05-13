#include <stdio.h>
#include <string.h>

int strend(char s[], char t[]);

int main(void) {
    char s[] = "test str end ends with end";
    char t[] = "end";

    printf("string ends with \"end\" ? -> %s\n", strend(s, t) ? "TRUE" : "FALSE");

    return 0;
}
int strend(char s[], char t[]) {
    int lens = strlen(s);
    int lent = strlen(t);

    if (!lent || lens < lent)
        return 0;

    while (lent > 1) {
        if (*(t + lent) != *(s + lens))
            return 0;
        lent--;
        lens--;
    }
    return 1;
}
