//Write a program to print a histogram of the frequencies of
// different characters in its input.

#include <stdio.h>
#include <libc.h>

int main(void) {
	char c;
	int i;
	int j;
	int len;
	int size;
	int maxCount = 'z' - 'a';
	unsigned int *charsCount = calloc(maxCount,sizeof(int));

	printf("size: ");
	scanf("%d", &size);


	for (i = 0; i < size + 1; ++i)
	{
		c = getchar();
		c -= 'a';
		charsCount[c]++;
	}

	for (i = 0; i < maxCount; ++i)
	{
		len = charsCount[i];
		for (j = 0; j < len; ++j)
		{
			printf("-");
		}
		printf("\n");
	}

	return 0;
}
