#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	char *s = "asdfghjklutrulkjlij7gfsffdsfd";
	char *p, *ss;
	int pp;
	
	p = strchr(s, '8');
	printf("%p %p %ld\n", s, p, p - s);
	
	ss = strdup(s);
	pp = strspn(ss, "abcdefghijklmnopqrstuvwxyz");
	printf("%s %p %d %c\n", ss, ss, pp, ss[pp]);
	ss[pp] = '\0';
	printf("%s\n", ss);
	
	p = strstr(ss, "hjklu");
	if (p) printf("%s %p %p %s\n", ss, ss, p, p);
	
	free(ss);
	
	return 0;
}
