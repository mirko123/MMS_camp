#include <stdio.h>
#include <libc.h>
#include <string.h>
void Strcat(char *s, char *t);

int main(int argc, char* argv[]) {
	char *input = strdup("test me");
	char *output = (char*)malloc(60);
	Strcat(output,input);
	printf("%s\n", output);
	return 0;
}
void Strcat(char *s, char *t) {
	int len = strlen(t);
	memcpy(s,t,len*sizeof(char));
	s[len] = '\0';
}