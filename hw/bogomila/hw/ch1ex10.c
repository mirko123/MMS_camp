#include<stdio.h>

int main(void) {

    int c;

    while( (c = fgetc(stdin)) != EOF) {
       
       if( c == '\t') printf("\\t");
       if( c == '\b') printf("\\b");
       if( c == '\\') printf("\\\\");
       else
        fputc(c, stdout);
}
   return 0;
}

