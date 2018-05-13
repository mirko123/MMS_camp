#include<stdio.h>


int main(void) {

   printf("From Fahrenheit to celsium");
   printf("\n");
 
   int lower = 0;
   int upper = 300;
   int step = 20;
   
   int fahr;
   
   for ( fahr = lower; fahr < upper ; fahr += step) 
      printf( "%3d %6.1f\n", fahr, ( 5.0 / 9.0 )*( fahr - 32) );

return 0;
   
}
