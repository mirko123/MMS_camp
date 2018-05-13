#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tokenize(char *s, char *delimiter[], char **tokens) {
	char *iterateString;
	iterateString = s;
	int dlen ;
	int slen = strlen(s);
	int idx = 0;
	char *tp, *dp;
	int j;
	int k;
	int i;
	for (k = 0; k < slen; k++) {
		for (i = 0; i < 3; i++) {
			dlen = strlen(delimiter[i]);
			for (tp = s + k, dp = delimiter[i], j = 0; j < strlen(delimiter[i]); j++) {
				if(*tp == *dp){	
				tp++;
				dp++;
				} else break;
			}	
			if (j == dlen) {
				*(tp - dlen) = '\0';
				tokens[idx++] = iterateString;
				iterateString = tp;
			}
		}
	}
	if (*iterateString != '\0') {
	tokens[idx++] = iterateString;
	}
	return idx;
}

int main(void) {
	char *s = strdup("123Helloabcdworld123firstabcdprogramabcdabcd123endFinalTokentheend123abcd");
	char *d[] = {"123", "abcd","FinalToken"};
	char **tokens;
	int n, j;
	
	tokens = (char **)calloc(strlen(s), sizeof (char *));
	
	n = tokenize(s, d, tokens);
	for (j = 0; j < n; j++)
		printf("token \"%s\"\n", tokens[j]);
	
	free(tokens);
	free(s);
	
	return 0;
}
