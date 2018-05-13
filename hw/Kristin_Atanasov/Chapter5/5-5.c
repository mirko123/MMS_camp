#include <stdio.h>

void strncpydos(char *s, char *t, int n);
int strncmpdos(char *s, char *t, int n);
void strncatdos(char *s, char *t, int n);

int main(void) {

    char *s;
    char *t = "test dos ok";
    char stest[] = "test cmp";
    char ttest[] = "test again";

    strncpydos(s, t, 8);
    printf("strcpydos -> %s\n", s);

    strncatdos(s, t, 6);
    printf("strncatdos -> %s\n",s);

    printf("strncmpdos -> %d\n", strncmpdos(stest, ttest, 10));

    return 0;
}



void strncpydos(char *s, char *t, int n) {
    while (n-- > 0 && (*s++ = *t++))
        ;
    *s = '\0';
    return;
}
int strncmpdos(char *s, char *t, int n) {
    while (n-- > 0 && *s == *t){
        if (*s == '\0' || n == 0)
            return 0;
        *s++;
        *t++;
    }
    return *s - *t;
}
void strncatdos(char *s, char *t, int n) {
    while (*s)
        ++s;
    while (n-- > 0 && (*t != '\0'))
        *s++ = *t++;
    *s = '\0';
    return;
}
