#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum {
	BUFSIZE = 128
};

char *getstr(FILE *f, const char *delimiters) {
	char *buf, *t;
	int N, p;
	int c;
	
	N = BUFSIZE;
	p = 0;
	
	buf = (char *)malloc(N * sizeof (*buf));
	if (!buf) goto out;
	
	while (1) {
		c = fgetc(f);
		if ((c == EOF) || strchr(delimiters, c)) {
			buf[p] = '\0';
			goto out;
		} else {
			buf[p++] = (char)(c & 0xff);
			if (p == N) {
				N += BUFSIZE;
				t = (char *)realloc(buf, N);
				if (!t) {
					buf[p - 1] = '\0';
					goto out;
				} else buf = t;
			}
		}
	}
out:
	return buf;
}

int main(void) {
	char *s;
	char *maxw;
	int maxlen, t;
	
	maxlen = 0;
	maxw = NULL;
	
	while (!feof(stdin)) {
		s = getstr(stdin, " .:;-!?()[]\n\t");
		if (s) {
			t = strlen(s);
			printf("\t%d\t%s\n", t, s);
			if (t > maxlen) {
				if (maxw) free(maxw);
				maxw = s;
				maxlen = t;
			} else free(s);
		}
	}
	
	printf("%d\t%s\n", maxlen, maxw);
	
	return 0;
}

