#include <stdio.h>

int bitlen(unsigned x);
unsigned setbits(unsigned x, unsigned p, unsigned n, unsigned y);

int main(void) {
    printf("(13, 2, 2, 7) = %u\n", setbits(13, 2, 2, 7));
    printf("(13, 4, 2, 6) = %u\n", setbits(13, 4, 2, 6));

    return 0;
}

int bitlen(unsigned x) {
    int len = 0;
    while(x) {
        len++;
        x >>= 1;
    }
    return len;
}

unsigned setbits(unsigned x, unsigned p, unsigned n, unsigned y) {
    unsigned lenx = bitlen(x);
    unsigned leny = bitlen(y);

    if (lenx < p + n || leny < n) {
        printf("Wrong Values =", p, n);
        return 0;

    } else {
        unsigned oldb = lenx - p - n;
        unsigned right = x & ~(~0 << oldb);
        unsigned newb = y & ~(~0 << n);
        x >>= lenx - p;
        x <<= n;
        x |= newb;
        x <<= oldb;
        x |= right;
        return x;
    }
}
