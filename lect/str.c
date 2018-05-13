#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	char ss[16] = {
		'0', '1', '2', '3', '4', '5', '6', '7',
		'0', '1', '2', '3', '4', '5', '6', '7'
	};
	char *s = strdup("abcdefgh");
	char *p;
	
	printf("%s\n", ss);
	
	printf("%s\n", s);
	for (p = s; *p; p++) {
		printf("%p\t%c\t%d\t%u\n", p, *p, (int)*p, (unsigned int)*p);
	}
	
	s[4] = '\0';
	printf("%s\n", s);
	
	free(s);
	
	return 0;
}
