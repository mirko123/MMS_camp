#include<stdio.h>

int main(void) {

    int c;
    int bCount = 0;

    while( (c = fgetc(stdin)) != EOF) {
         if( c == ' ') bCount++;
         if( bCount <= 1) fputc(c, stdout);
         else  
            bCount = 0;
}

   return 0;
}


