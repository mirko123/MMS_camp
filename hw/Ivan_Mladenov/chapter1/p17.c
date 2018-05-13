#include <stdio.h>
#include <stdlib.h>

enum {
	MAXLEN = 4096
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

int main(void){
	char s[MAXLEN];
	char v[MAXLEN];
	int i = 0, j = 0;
	int c;	
	
	int len = 0;
	int max_len = 0;

	while((len = max_length(s)) > 0){	

		if(len > 40){
			while(v[j] = s[j]) ++j;
			printf("%d %s \n", len, v);
		}
		j = 0;

		
	}

return 0;
}
