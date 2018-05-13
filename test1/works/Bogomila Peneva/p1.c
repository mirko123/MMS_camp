#include<stdio.h>

#include "p1.h"

void clear( unsigned int *array, int N) {
      
    int j;

    for(j=0; j < N;j++) {
      set(array, N, j, 0);
    }
 }

int get(const unsigned int *array, int N, int bit){
   if(bit < 0 || N <= bit) return -1;
   
   int j;
   unsigned int* temp;
   
   for(j= 0; j < N; j++) {
     *(temp + j) = *(array + j);
  }

   return (*temp >> bit) & 1u;

   }

}
int set( unsigned int *array, int N, int bit, int boolean) {
    
    if(bit < 0 || N <= bit) return -1;

    if( boolean == 0) {
       *array &= ~(1u << bit);
        
    }
    
   else if(boolean == 1) {
      *array |= (1u << bit);
    
   }
   
   else {
      return -1;
   }
    
    
}
   
