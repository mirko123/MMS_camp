#include <stdio.h>
#include <libc.h>
int main(int argc, char *argv[]) {
	char *str = strdup("line1\nline2\nline3\nline4\nline5");
	int count = argc == 2? atoi(argv[1] + 1) : 1;
	int index = strlen(str);
	while(str[index - 1] && 0 < count) {
		if(str[index] == '\n') {
			count--;
		}
		index--;
	}
	printf("%s\n", str + index);


	return 0;
}








