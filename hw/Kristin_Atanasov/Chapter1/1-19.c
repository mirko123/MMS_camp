#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int maxline);
void printReverse(char s[], int i);

int main() {
    int len;
    char line[MAXLINE];
    while ((len = getline(line, MAXLINE)) > 0) {
        printReverse(line, len);
    }
  }
int getline(char s[], int lim) {
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        s[i] = c;
    }
    s[i] = '\0';
    return i;
}
void printReverse(char s[], int i){
    int j;
    for (j = i; j >= 0; j--){
        printf("%c", s[j]);
    }
    printf("\n");
    return;
}

