#include <stdio.h>
#include <string.h>

enum {
	LEN = 16
};

int main(void) {
	char buf[LEN];
	int j;
	char *p;
	char *words[] = {
		"1", "3", "2", "5",
		"4", "6", "7", "9",
		"8", "8", "10", "11",
		"13", "12",
		NULL
	};
	
	p = strcpy(buf, "asdfg");
	printf("%p %p %s\n", buf, p, buf);
	
	for (j = 0; j < LEN; j++)
		buf[j] = 0xff;

	p = strncpy(buf, "asdfgaaaaaaaaaaaaaaaaaa", sizeof(buf) / sizeof(buf[0]));
	buf[LEN - 1] = '\0';
	printf("%p %p %s\n", buf, p, buf);
	
	for (j = 0; j < LEN; j++)
		printf("%x\n", (unsigned int)buf[j]);
	
	for (j = 0; words[j]; j++)
		if (words[j + 1]) printf("%s\t%s\t%d\n",
			words[j],
			words[j + 1],
			strcmp(words[j], words[j + 1]));
	
	return 0;
}
