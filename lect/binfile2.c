#include <stdio.h>

int main(void) {
	FILE *f;
	int buf[10], j;
	size_t rd;
	
	f = fopen("bin_file", "r");
	if (!f) goto out;
	rd = fread(buf, sizeof(int), sizeof(buf) / sizeof(buf[0]), f);
	printf("%d\n", rd);
	fclose(f);
	for (j = 0; j < 10; j++)
		printf("%d\n", buf[j]);
out:
	return 0;
}
