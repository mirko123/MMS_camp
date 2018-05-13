#include<stdio.h>

#include "p2.h"

void clear( unsigned char *array, int N) {
     int j;
     for( j = 0; j < N; j++) 
   {
       free(array[j]);
   }
}

int get(const unsigned char *i, int N, int bit) {
     

}
