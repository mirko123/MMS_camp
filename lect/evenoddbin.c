#include <stdio.h>

int main(int argc, char *argv[]) {
	FILE *even, *odd;
	int ie, io, dummy;
	size_t re, ro;
	
	if (argc != 3) goto bad0;
	
	if (!(even = fopen(argv[1], "r"))) goto bad0;
	if (!(odd = fopen(argv[2], "r"))) goto bad1;
	(void)fread(&dummy, sizeof (dummy), 1, odd);
	
	for (;;) {
		re = fread(&ie, sizeof (ie), 1, even);
		(void)fread(&dummy, sizeof (dummy), 1, even);
		ro = fread(&io, sizeof (io), 1, odd);
		(void)fread(&dummy, sizeof (dummy), 1, odd);
		fprintf(stderr, "%ld %d %ld %d\n", re, ie, ro, io);
		if ((!re) && (!ro)) break;
		if (re) (void)fwrite(&ie, sizeof (ie), 1, stdout);
		if (ro) (void)fwrite(&io, sizeof (io), 1, stdout);
	}
	
	fclose(odd);
	fclose(even);
	return 0;
bad1:
	fclose(even);
bad0:
	return 1;
}
