#include <stdio.h>

int main(void) {
	FILE *f;
	int c;
	unsigned int mask;
/*
	f = fopen("new_file", "w+");
	if (!f) goto out;
	fprintf(f, "we've just created a file!\n");
*/
/*
	f = fopen("new_file", "a");
	if (!f) goto out;
	fprintf(f, "and appended a line to it\n");
*/
	f = fopen("new_file", "r");
	if (!f) goto out;
	while ((c = fgetc(f)) != EOF) {
		for (mask = 0x80u; mask; mask >>= 1)
			printf("%d", !!(c & mask));
	}
	fclose(f);
out:
	return 0;
}
