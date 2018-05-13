#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int maxline);
void trim(char line[]);

int main() {
  int len;
  char line[MAXLINE];
  while ((len = getline(line, MAXLINE)) > 0) {
    trim(line);
    if (line[0] != '\n' && line[0] != '\0') {
      printf("%s", line);
    }
  }
}
int getline(char s[], int lim) {
  int c, i;
  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
    s[i] = c;
  }
  if (c == '\n') {
    s[i] = c;
    i++;
  }
  s[i] = '\0';
  return i;
}
void trim(char line[]) {
  char c;
  int i;
  int flag = -1;
  for (i = 0; (c = line[i]) != '\n' && c != '\0'; i++) {
    if (c == ' ' || c == '\t') {
      if (flag == -1) {
        flag = i;
      }
    } else {
      flag = -1;
    }
  }
  if (flag != -1 && i > 0) {
    if (line[i] == '\n') {
      line[flag++] = '\n';
    }
    line[flag] = '\0';
  }
}
