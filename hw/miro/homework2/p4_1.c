#include <stdio.h>
#include <libc.h>
#include <string.h>

int strindex(const char *str,const char termn);

int main(int argc, char* argv[]) {
	int index = strindex("0123456789",'9');
	printf("%d\n", index);
	return 0;
}

int strindex(const char *str,const char termn) {
	int index = 0;
	int length = strlen(str);
	for (index = 0; index < length; ++index)
	{
		if(str[index] == termn) {
			return index;
		}
	}
	return -1;
}