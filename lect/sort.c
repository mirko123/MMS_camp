#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *_p1, const void *_p2);

int main(void) {
	int j;
	char *words[14] = {
		"b", "bbf", "bvf", "gf",
		"8", "6", "7", "t",
		"rel", "er", "re", "rs",
		"pok", "tua"
	};
	
	for (j = 0; j < 14; j++)
		printf("%s ", words[j]);
	fputc('\n', stdout);
	qsort(words, sizeof (words) / sizeof (words[0]), sizeof (words[0]), &cmp);
	for (j = 0; j < 14; j++)
		printf("%s ", words[j]);
	fputc('\n', stdout);
	
	return 0;
}

int cmp(const void *_p1, const void *_p2) {
	printf("cmp called - %s %s\n", *(const char **)_p1, *(const char **)_p2);
	return -strcmp(*(const char **)_p1, *(const char **)_p2);
}

