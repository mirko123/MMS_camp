#include<stdio.h>
#include<stdlib.h>
/*
int main(void){
        int a=1;

        printf("%d %d\n",a++,++a);

        return 0;
}

int main(void){
    int a= -1, b=1;
    printf("%d %d\n", a >> 1, a / 2);  
    printf("%d %d\n", b >> 1, a / 2);

    printf("%d\n ", -a);  
    printf("%d\n", -b);

    printf("%d\n", b & 0x80000000);
    printf("%d\n", b | 0x80000000);
 
    printf("%d\n", a & 0x80000000);
    printf("%d\n", a | 0x80000000);
 
    return 0;
}

int main(void){
   
    unsigned mask;
    int a;

    for(a=-10; a<11; a++){
          printf("%d\t",a);

         for (mask = 0x80000000u; mask; mask >>=1)
              printf("%u", !!((unsigned int) a & mask));
         printf("\n");
    }

    return 0;
}*/
void printb(unsigned int a);
unsigned int getbit(unsigned int a, int n);
void set1(unsigned int* a, int n);
void set0(unsigned int* a, int n);

int main(void){
    unsigned int a,  t;
    int j;
    
    a=0xf00fc7c8u;

     
    

    for(t = 0u, j=0,j<32;j+=2)
        t += getbit(a, j);
        printf("%u\n", t);
    
   
    return 0;

}



void printb(unsigned int a){
     unsigned int mask;
     for (mask = 0x80000000u; mask; mask >>=1)
              printf("%u", !!( a & mask));
     return;
}

unsigned int getbit(unsigned int a, int n){
        return (a >> n) & 1u;
}

void set1(unsigned int* a, int n){
     *a |= (1u << n);
     return;
}

void set0(unsigned int* a, int n){
     *a &= ~(1u << n);
     return;
}
































