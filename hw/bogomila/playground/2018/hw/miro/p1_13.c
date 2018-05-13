#include <stdio.h>
#include <libc.h>

int main(void) {
	int i;
	int j;
	int size;
	int maxCount = 5;
	int len;
	int *arr = calloc(maxCount,sizeof(int));
	char *word = malloc(maxCount*sizeof(int));

	printf("size: ");
	scanf("%d", &size);


	for (i = 0; i < size; ++i)
	{
		scanf("%s", word);
		len = strlen(word);
		arr[len]++;
	}

	for (i = 0; i < maxCount; ++i)
	{
		len = arr[i];
		for (j = 0; j < len; ++j)
		{
			printf("-");
		}
		printf("\n");
	}

	return 0;
}
