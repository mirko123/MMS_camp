#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	char ss[16] = {
		'0', '1', '2', '3', '4', '5', '6', '7',
		'8', '9', 'a', 'b', 'c', 'd', 'e', 'f'
	};
	unsigned int a = 0xf70fc7c8, mask;
	int j;
	
	for (j = 7, mask = 0xf0000000u; j >= 0; j--) {
		printf("%c", ss[(a & mask) >> (4 * j)]);
		mask >>= 4;
	}
	printf("\n");
	
	return 0;
}
