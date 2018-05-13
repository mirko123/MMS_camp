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

void squeeze(char s1[], char s2[])
{
	int i, j, k;

	i = 0;
	while (s2[i] != '\0') {
		j = 0;
		while (s1[j] != '\0') {
			if (s1[j] == s2[i]) {
				k = j;
				while ((s1[k] = s1[++k]) != '\0');
			} else ++j;
		}
		++i;
	}
}

int main(void){
	int len;
	char s1[MAXLINE];
	char s2[MAXLINE];

	while ((len = max_length(s1, MAXLINE)) == 0);

	while ((len = max_length(s2, MAXLINE)) == 0);

	squeeze(s1, s2);
	printf("Result is %s\n", s1);

}
