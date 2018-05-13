#include <stdio.h>

int main(int argc, char *argv[], char **envp) {
	int j;
	char **p;
	
	for (j = 0; j < argc; j++)
		printf("%s\n", argv[j]);
	
	for (p = envp; *p; p++)
		printf("%s\n", *p);
	
	return 0;
}
