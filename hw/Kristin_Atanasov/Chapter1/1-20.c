#include <stdio.h>

#define TABWIDTH 8
#define MAXLINE 1000

int line(char s[], int lim);
void detab(char src[], char tar[]);

int main() {
    int len;
    char s[MAXLINE];
    char t[MAXLINE * TABWIDTH];

    while (line(s, MAXLINE)) {
        detab(s, t);
        printf("%s", t);
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
void detab(char src[], char tar[]) {
    int i;
    int j = 0;
    int spacewidth;
    char c;
    for (i = 0; (c = src[i]) != '\0'; i++) {
        if (c != '\t') {
            tar[j++] = c;
        } else {
            spacewidth = TABWIDTH - (j % TABWIDTH);
        while (spacewidth-- > 0) {
            tar[j++] = '#';
        }
        }
    }
    tar[j] = '\0';
}
