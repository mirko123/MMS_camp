#include <stdio.h>
#include <stdlib.h>
int isValid(const char first) {
    if(('0'<=first && first<='9') ||
        ('a'<=first && first<='z') ||
        ('A'<=first && first<='Z') ||
        first == ' ') {
        return 1;
    }
    return 0;
}

int cmpfunc (const void * a, const void * b) {
    return ( *(char*)a - *(char*)b );
}

int cmpfuncDEC (const void * a, const void * b) {
    return ( *(char*)b - *(char*)a );
}
int cmpfuncNoMatterUpperLowerCasse (const void * a, const void * b) {
    int first = *(char*)a;
    int second = *(char*)b;
    int diff1 = first - second;
    int diff2 = ('a' - 'A');
    int diff3 = ( *(char*)a - *(char*)b - ('a' - 'A'));
    if(*(char*)a >= 'a' && *(char*)b >= 'a') {
        return ( *(char*)a - *(char*)b );
    }
    else if(*(char*)a >= 'a' && *(char*)b >= 'A') {
        return ( *(char*)a - *(char*)b - ('a' - 'A'));
    }
    else if(*(char*)a >= 'A' && *(char*)b >= 'a') {
        return ( *(char*)a - *(char*)b - ('A' - 'a'));
    }
    else if(*(char*)a >= 'A' && *(char*)b >= 'A') {
        return ( *(char*)a - *(char*)b );
    }
   	return ( *(char*)a - *(char*)b );
}

int main(int argc, char *argv[]) {
    char values[] = "abABbaABaAbBaAabBa";
    int size = (sizeof(values) - 1) / sizeof(values[0]);
    int i;

    if(argc == 1) {
        printf("arguments = 0\n");
        return 0;
    }
    for( i = 0 ; i < size; i++ ) {
        printf("%c ", values[i]);
    }
    
    qsort(values, size, sizeof(char), cmpfuncDEC);
    if(argc > 2 && argv[2][1] == 'd') {
        for (i = 0; i < size; ++i)
        {
            if(!isValid(values[i])) {
                printf("\n  only on letters, numbers and blanks \n");
                return 0;
            }
        }
    }
    else if(argc > 1 && argv[1][1] == 'f'){
        qsort(values, size, sizeof(char), cmpfuncNoMatterUpperLowerCasse);
    }
    
    if(argc > 2 && argv[2][1] == 'd') {
        for (i = 0; i < size; ++i)
        {
            if(!isValid(values[i])) {
                printf("\n  only on letters, numbers and blanks \n");
                return 0;
            }
        }
    }
    else if(argc > 2 && argv[2][1] == 'f'){
        qsort(values, size, sizeof(char), cmpfuncNoMatterUpperLowerCasse);
    }
    
    
    
    printf("\nAfter: \n");
    for( i = 0 ; i < size; i++ ) {   
        printf("%c ", values[i]);
    }
    printf("\n");
    return 0;
}








