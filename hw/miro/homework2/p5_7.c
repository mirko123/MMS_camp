// Rewrite readlines to store lines in an array 
// supplied by main, rather than calling alloc to 
// maintain storage. How much faster is the program?
#include <stdio.h>
#include <libc.h>
#include <string.h>

void readlines(char *lines[], char* linesArr, int lineCount);

int main(int argc, char* argv[]) {
	char *first = strdup("test me");
	char *second = strdup("1111 11");
	char *thr = strdup("fffff");
	char *arr[] = {first, second, thr};
	char *res = (char*)malloc(1000);
	readlines(arr,res,3);
	// int result = Strend(str,sufix);
	printf("%s\n", res);
	return 0;
}

void readlines(char *lines[], char* linesArr, int lineCount) {
	char* line;
	int i = 0;
	int j = 0;

	for (i = 0; i < lineCount; ++i) {
		line = lines[i];
		while(*line) {
			*linesArr = *line;
			linesArr++;
			line++;
		}
	}
	*linesArr = '\0';
}

























