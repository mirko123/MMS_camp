#include <stdio.h>

int bitcount(unsigned int x);

int main(void) {
    printf("500 has %u bits\n", bitcount(500));
    printf("1111444 has %u bits\n", bitcount(1111444));

    return 0;
}
int bitcount(unsigned int x) {
    int len = 0;
    while(x) {
        len++;
        x >>= 1;
    }
    return len;
}

