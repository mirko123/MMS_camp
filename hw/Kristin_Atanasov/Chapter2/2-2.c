#include <stdio.h>

int main(void) {
    int i, c, lim=1000;
    char s[lim];
/*    for (i=0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
            s[i] = c; */
//Write a loop equivalent to the for loop above without using && or ||.
    i = 0;
    while(i < lim-1){
        if ((c = getchar()) != '\n')
            break;
        if ((c = getchar()) != EOF)
            break;
        s[i] = c;
        i++;
    }
    return 0;
}
