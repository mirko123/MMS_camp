#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int getline(char s[], int lim);
int strindex(char s[], char t[]);
char pattern[] = "mms";

int main(void) {
    char line[MAXLINE];
    while (getline(line, MAXLINE) > 0)
        printf("Position = %d\n", strindex(line, pattern));;

    return 0;
}
int getline(char s[], int lim) {
    int c, i;
    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}
int strindex(char s[], char t[]) {
    int slen = strlen(s);
    int tlen = strlen(t);
    int i, j, k;

    for (i = slen - tlen; s[i] != '\0'; i--) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (t[k] == '\0')
            return i;
    }
    return -1;
}
