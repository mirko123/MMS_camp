#include <stdio.h>

int bitlen(unsigned x);
unsigned rightrot(unsigned x, unsigned n);

int main(void) {
    printf("(15, 2) = %u\n", rightrot(11, 1));
    printf("(2000, 17) = %u\n", rightrot(1024, 14));

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
unsigned rightrot(unsigned x, unsigned n) {
    int len = bitlen(x);
    if (len) {
        n %= len;
        if (n) {
            unsigned right = x & ~(~0 << n);
            return right << len - n ^ x >> n;
        } else {
            return x;
        }
    } else {
    return 0;
  }
}

