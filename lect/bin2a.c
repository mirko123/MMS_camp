#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int c, val;
	char buf[2] = { '\0', '\0' };
	int bitc, outc;
	
	outc = 0;
	bitc = 7;
	while ((c = fgetc(stdin)) != EOF) {
		buf[0] = (char)c;
		val = atoi(buf);
		outc |= val << bitc;
		bitc--;
		if (bitc < 0) {
			fputc(outc, stdout);
			outc = 0;
			bitc = 7;
		}
	}
	
	return 0;
}
