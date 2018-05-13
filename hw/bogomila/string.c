#include<stdio.h>
#include<stdlib.h>
#include<string.h>

  

int main(void){
    char* s = strdup("abcd");// taka veche moje da modificirame
    char* p;
    
    printf("%s\n", s);
    for(p = s; *p; p++){
       printf("%p\t%c\t%d\t%u\n", p, *p, (int)*p, (unsigned int)*p);
    }
    free(s);

    return 0;
    
    }
