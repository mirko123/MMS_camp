#include<stdio.h>

int main(void){
    int a[10], *b;
     b=a;
     *(b + 3) = 5;
     printf("%d\n", a[3]);
     printf("%lu\t%lu\n", sizeof(b), sizeof(long));
     printf("%lu\t%lu\n", sizeof(a), sizeof(a)/sizeof (a[0]));

     printf("%p %p\n", a, a + 1);

     *((int *)NULL)=0;
     
     return 0;

}
