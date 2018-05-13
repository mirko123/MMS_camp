#include <stdio.h>
#include <libc.h>
#include <string.h>


int main(int argc, char* argv[]) {
	char *src = strdup("test me");
	char *dst = strdup("1111 11");
	char *res = Strncat(src,dst,100);
	// int result = Strend(str,sufix);
	printf("%s\n", res);
	return 0;
}