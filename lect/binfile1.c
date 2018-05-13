#include <stdio.h>

int main(void) {
	FILE *f;
	int buf[10], j;
	size_t written;
	
	for (j = 0; j < 10; j++)
		buf[j] = -j;
	f = fopen("bin_file", "w");
	if (!f) goto out;
	written = fwrite(buf, sizeof(int), sizeof(buf) / sizeof(buf[0]), f);
	printf("%d\n", written);
	fclose(f);
out:
	return 0;
}
