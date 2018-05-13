#include <stdio.h>
#include <ctype.h>

#define SIZE 10
#define BUFSIZE 100

int getfloat(double *p);
int getch(void);
void ungetch(int);

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

int main(void){
    double arr[SIZE], c;
    int n;

    for (n = 0; n < SIZE && (c = getfloat(&arr[n])) != EOF; n++) {
        if (c)
            printf("Correct input %f\n", arr[n]);
        else
            printf("Incorrect input.\n");
    }
    return 0;
}
int getfloat(double *p) {
    int c, nc, sign, pwr;

    pwr = 1;

    while (isspace(c = getch()));

    if (!isdigit(c) && c != EOF && c != '-' && c != '+' && c != '.') {
        ungetch(c);
        return 0;
    }

    sign = c == '-' ? -1 : 1;

    if (c == '-' || c == '+') {
        nc = getch();
        if (isdigit(nc)) {
            c = nc;
        } else {
            ungetch(nc);
            ungetch(c);
            return 0;
        }
    }

    for (*p = 0.0; isdigit(c); c = getch()) {
        *p = 10.0 * *p + (c - '0');
    }


    if (c == '.') {
        c = getch();
    }

    for (; isdigit(c); c = getch()) {
        *p = 10.0 * *p + (c - '0');
        pwr = pwr * 10.0;
    }

    *p = sign * *p / pwr;

    if (c != EOF) {
        ungetch(c);
    }

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
