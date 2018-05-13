#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	char *s = "as#df$gh%jk", *token = "#$%";
	char *ss, *p;
	
	ss = strdup(s);
	
	for (p = strtok(ss, token); p; p = strtok(NULL, token))
		printf("%s\n", p);
	
	free(ss);
	
	return 0;
}
