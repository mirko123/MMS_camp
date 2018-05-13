#include<stdio.h>

unsigned setbits(x, p, n, y) {
    
    return x & ~(~(~0 << n) << (p+1-n)) | ( y & ~(~0<<n)) << (p+1-n);

    
}

