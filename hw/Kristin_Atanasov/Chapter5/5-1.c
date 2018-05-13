#include <stdio.h>
#include <ctype.h>

#define SIZE 10
#define BUFSIZE 100

int getint(int *);
int getch(void);
void ungetch(int);

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

int main(void){
    int n, arr[SIZE], c;

    for (n = 0; n < SIZE && (c = getint(&arr[n])) != EOF; n++) {
        if (c)
            printf("Correct input %d\n", arr[n]);
        else
            printf("Incorrect input.\n");
    }
    return 0;
}
/* getint: get next integer from input into *pn */
int getint(int *pn) {
    int c, sign, nc;

    while (isspace(c = getch())) /* skip white space */
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c); /* it is not a number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        if (!isdigit(nc = getch())) {
            ungetch(nc);
            ungetch(c);
            return 0;
        } else
            c = nc;
    }
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}
int getch(void) { /* get a (possibly pushed-back) character */
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) { /* push character back on input */
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
