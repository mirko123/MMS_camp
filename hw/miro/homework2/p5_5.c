// Write versions of the library functions strncpy, strncat, 
// and strncmp, which operate on at most the first n characters 
// of their argument strings. For example, strncpy(s,t,n) 
// copies at most n characters of t to s. Full descriptions are in Appendix B. 
#include <stdio.h>
#include <libc.h>
#include <string.h>
char* Strncpy(char *dst, char *src, int length);
char* Strncat(char *first, char *second, int length);
int Strncmp(char *dst, char *src, int length);

int main(int argc, char* argv[]) {
	char *src = strdup("test me");
	char *dst = strdup("1111 11");
	char *res = Strncat(src,dst,100);
	// int result = Strend(str,sufix);
	printf("%s\n", res);
	return 0;
}

char* Strncpy(char *dst, char *src, int length) {
	int counter = 0;

	while(*src && counter < length) {
		*dst = *src;
		dst++;
		src++;
		counter++;
	}
	*dst = '\0';
	return dst;
}
char* Strncat(char *first, char *second, int length) {
	int firstLength = strlen(first);
	int secondLength = strlen(second);
	int counter = 0;
	char *newString = (char*)malloc((firstLength + secondLength)*sizeof(char));
	char *begin = newString;
	while(*first && counter < length) {
		*newString = *first;
		first++;
		newString++;
		counter++;
	}
	while(*second && counter < length) {
		*newString = *second;
		second++;
		newString++;
		counter++;
	}
	*newString = '\0';
	return begin;
}
int Strncmp(char *first, char *second, int length) {
	int counter = 0;
	while(*first && *second && counter < length) {
		if(*first > *second) {
			return 1;
		}
		else if(*first < *second) {
			return -1;
		}
		first++;
		second++;
	}
	return 0;
}

















