#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	char *buf0, *buf1;
	
	buf0 = strdup("string1");
	if (!buf0) goto bad0;
	buf1 = strdup("string2");
	if (!buf1) goto bad1;
	
	printf("%s %s\n", buf0, buf1);
	
	free(buf1);
bad1:
	free(buf0);
bad0:
	return 0;
}
