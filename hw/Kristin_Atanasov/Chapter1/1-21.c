#include <stdio.h>

#define TABWIDTH 8
#define MAXLINE 1000

int line(char s[], int lim);
void entab(char s[]);

int main(void) {
    int len;
    char s[MAXLINE];

    while (line(s, MAXLINE)) {
        entab(s);
        printf("%s", s);
    }
}

int line(char s[], int lim) {
    char c;
    int i = 0;
    while ((c = getchar()) != EOF && c != '\n' && i < lim - 1) {
        s[i++] = c;
    }
    if (c == '\n') {
        s[i++] = '\n';
    }
    s[i] = '\0';
    return i;
}

void entab(char s[]) {
    int i;
    int j;
    int tp = -1;
    int sp = -1;
    char c;
    for (i = 0, j = 0; (c = s[i]) != '\0'; i++, j++) {
        s[j] = c;
        if (c == '\t') {
        tp = TABWIDTH - 1;
        } else {
            tp++;
        }
        if (c == ' ') {
        if (sp == -1) {
            sp = tp;
        }
        } else {
            sp = -1;
        }
        if (tp == TABWIDTH - 1) {
            if (sp != -1) {
                int spacewidth = TABWIDTH - sp;
                j = j - spacewidth + 1;
                s[j] = '#';
                sp = -1;
            }
            tp = -1;
        }
    }
    s[j] = '\0';
    return;
}
