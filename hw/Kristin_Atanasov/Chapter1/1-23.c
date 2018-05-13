#include <stdio.h>

int main(void) {
    char prevc;
    char c;
    char nextc;
    while ((c = getchar()) != EOF) {
        if (c == '"') {
            while ((c = getchar()) != '"' || prevc == '\\') {
                    putchar(prevc = c);
            }
        putchar(prevc = c);

        } else if (c == '/') {
            nextc = getchar();
            if (nextc == '/') {
                while ((c = getchar()) != '\n')
                    ;
                putchar('\n');
            } else if (nextc == '*') {
                prevc = getchar();
                while ((c = getchar()) != '/' || prevc != '*') {
                    prevc = c;
                }
            } else {
                putchar(c);
                putchar(prevc = nextc);
            }
        } else {
            putchar(prevc = c);
        }
    }
}
