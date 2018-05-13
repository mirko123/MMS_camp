#include <stdio.h>

int bitlen(unsigned x);
unsigned invert(unsigned x, unsigned p, unsigned n);

int main() {
    printf("(6, 1, 2) = %u\n", invert(5, 1, 1));
    printf("(5, 4, 1) = %u\n", invert(5, 4, 1));
}
int bitlen(unsigned x) {
    int len = 0;
    while(x) {
        len++;
        x >>= 1;
    }
    return len;
}
unsigned invert(unsigned x, unsigned p, unsigned n) {
    int len = bitlen(x);

    if (len < p + n) {
        printf("Wrong Values =", p, n);
        return 0;
    } else {
    unsigned oldb = len - p - n;
    unsigned right = x & ~(~0 << oldb);
    x >>= oldb;
    x ^= ~(~0 << n);
    x <<= oldb;
    x |= right;
    return x;
  }
}
