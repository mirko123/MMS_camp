#include <stdio.h>
#include <string.h>

void squeeze(char s1[], char s2[]);

int main(void) {
    char s1[] = "asdasdnsidfjgnidufg43321";
    char s2[] = "asdasdafasdaf";

    squeeze(s1, s2);
    printf("%s\n", s1);

    return 0;
}
void squeeze(char s1[], char s2[]){
    int i, j, k;
    int flag = 0;

    for(i = j = 0; s1[i] != '\0'; i++) {
        flag = 0;
        for(k = 0; s2[k] != '\0' && (flag == 0); k++) {
            if(s2[k] == s1[i]) {
                flag = 1;
            }
        }
        if(flag == 0) {
            s1[j++] = s1[i];
        }
    }
    s1[j] = '\0';
}
