#include <stdio.h>

int main(int argc, char *argv[]) {
	FILE *even, *odd;
	int ce, co;
	
	if (argc != 3) goto bad0;
	
	if (!(even = fopen(argv[1], "r"))) goto bad0;
	if (!(odd = fopen(argv[2], "r"))) goto bad1;
	(void)fgetc(odd);
	
	for (;;) {
		ce = fgetc(even);
		(void)fgetc(even);
		co = fgetc(odd);
		(void)fgetc(odd);
		if ((ce == EOF) && (co == EOF)) break;
		if (ce != EOF) fputc(ce, stdout);
		if (co != EOF) fputc(co, stdout);
	}
	
	fclose(odd);
	fclose(even);
	return 0;
bad1:
	fclose(even);
bad0:
	return 1;
}
