#include <stdio.h>

enum {
	MAXLINE = 4096
};

int max_length(char s[]){
	int i, j;
	int c;

	for (i = 0, j = 0; (c = getchar()) != EOF && c != '\n'; ++i) {		//read from file "text" for input
		
		s[j++] = c;
	}
	
	s[j] = '\0';
return i;	
}

long htoi(char s[])
{
	long n;
	int i, c;

	n = 0;
	for (i = 0; s[i] != '\0'; ++i) {
		c = s[i];
		if (i == 0 && c == '0' && (s[1] == 'x' || s[1] == 'X')) {
			i = 1;
			continue;
		}
		n *= 16;
		if (c >= '0' && c <= '9')
			n += c - '0';
		else if (c >= 'a' && c <= 'f')
			n += c - 'a';
		else if (c >= 'A' && c <= 'F')
			n += c - 'A';
	}

    return n;
}

int main(void){

	int len;
	char line[MAXLINE];

	while ((len = max_length(line)) > 0)
		printf("%lu\n", htoi(line));

return 0;
}
