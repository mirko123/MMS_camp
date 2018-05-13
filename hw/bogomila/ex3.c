 #include<stdio.h>
#include<string.h>
#include<stdlib.h>


/*
int main(void){
    int j;

    for(j=0; j<100; j++)
        printf("%d\t%d\n",j, ( j % 7 ) ? 0 : 1)
    return 0;
}

int main(void){
    int j;

    for(j=0; j<100; j++)
        switch(j % 3) {
        case 0:
               printf("%d = 0 mod 3\n",j);
              break;
        case 1:
               printf("%d = 1 mod 3\n",j);
               break;
        default:
                printf("%d = 1 mod 3\n",j);
}
    return 0;


}


int main( void){
   
    int j;

    for(j=0; j<100; j++)
  {
     if(!(j % 14)) printf("FIZZBUZZ\n");
     else if(!(j % 2)) printf("FIZZ\n");
     else if(!(j % 3)) printf("BUZZ\n");
}
 return 0;
}


int main( void){
   
    int j = 0;

label: 
    printf("%d\n",j++);
    if(j < 10) goto label;

    return 0;
}



int main(void){

    char *buf0, *buf1;
     
     buf0 = strdup("string1");
     if(!buf0) goto bad0;
      buf1 = strdup("string2");
     if(!buf1) goto bad1;
      printf("%s %s\n", buf0, buf1);

      free(buf1);
bad1:
       free(buf0);
bad0:
      return 0;
}




void f(int num){
   
    if(!num) return;
    f(num/2);
    printf("%d", num % 2);
    return;
}


int main( void){
   int j;

   for(j = 1; j < 128; j++) {
       printf("%d\t",j);
       f(j);
       printf("\n");
}


 return 0;
}
  
*/



struct test {
        int i1;
        long l1;
        char c1;
        short s1;
};

typedef struct test test;

int main(void) {

     test t;
     printf("%lu\n", sizeof(t));
     printf("%p\n", &t.i1);
     printf("%p\n", &t.l1);
     printf("%p\n", &t.c1);
     printf("%p\n", &t.s1);
    return 0;
}




























