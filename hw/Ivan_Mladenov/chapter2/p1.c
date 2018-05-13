#include <stdio.h>
#include <limits.h>

int main(void)
{	
	printf("Range of char is from %d to %d \n", CHAR_MIN, CHAR_MAX);
	printf("Range of unsigned char is from %u to %u \n", 0, UCHAR_MAX);

	printf("Range of short int is from %hd to %hd \n", SHRT_MIN, SHRT_MAX);
	printf("Range of unsigned short int is from %hu to %hu \n", 0, USHRT_MAX);

	printf("Range of int is from %d to %d \n", INT_MIN, INT_MAX);
	printf("Range of unsigned int is from %u to %u \n", 0, UINT_MAX);

	printf("Range of long is from %ld to %ld \n", LONG_MIN, LONG_MAX);
	printf("Range of unsigned long is from %lu to %lu \n", 0, ULONG_MAX);

    return 0;
}
