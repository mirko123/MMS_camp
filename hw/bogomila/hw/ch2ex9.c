#include<stdio.h>

int bitcount(unsigned x) {
    
    int count;
    
    for(count = 0; x != 0; x &= (x -1) )
    {
        count++;
    }
    
    return count;
}
