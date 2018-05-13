#include <stdio.h>
/* count lines in input */
main() {
    int c, nl, t, bl;
    nl = 0;
    t = 0;
    bl = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\n')
            ++nl;
        if (c == '\t')
            ++t;
        if (c == ' ')
            ++bl;
    }
    printf("%d\t%d\t%d\n", nl, t, bl);
}
