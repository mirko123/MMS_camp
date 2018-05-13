#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tokenize(char *s, const char *delimiter, char **tokens) {
	int dlen = strlen(delimiter);
	char *tp, *dp;
	int idx;
	int j;
	
	for (
			idx = 0, tp = s, dp = strstr(s, delimiter);
			dp;
			dp = strstr(dp, delimiter)) {
		for (j = 0; j < dlen; j++)
			dp[j] = '\0';
		tokens[idx++] = tp;
		dp += dlen;
		tp = dp;
	}
	tokens[idx++] = tp;
	
	return idx;
}

int main(void) {
	char *s = strdup("123ab123cd123123ef123gh123");
	char *d = "123";
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
