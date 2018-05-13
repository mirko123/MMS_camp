#include <stdio.h>
#include <libc.h>
#include <string.h>
int Strend(char *s, char *t);

int main(int argc, char* argv[]) {
	char *str = strdup("test me");
	char *sufix = strdup("me");
	int result = Strend(str,sufix);
	printf("%d\n", result);
	return 0;
}
int Strend(char *str, char *sufix) {
	int strLength = strlen(str);
	int sufixLength = strlen(sufix);
	int strIndex, sufixIndex;
	for(strIndex = strLength - 1, sufixIndex = sufixLength - 1; 
		strIndex >= 0 && sufixIndex >= 0; strIndex--, sufixIndex--) 
	{
		if(str[strIndex] != sufix[sufixIndex]) {
			return false;
		}
	}

	return true;
}