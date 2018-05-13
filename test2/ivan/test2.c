#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"

enum {
	BUFSIZE = 128;
};

void calc(FILE *in, FILE *out, queue_object *q) {
	char *dc = "#";		//define composition
	char *cc = "$";		//compute composition
	char *token = "#$";
	char *buf, *t;
	
	int j = 0, i;
	
	int N, p;
	
	char **line, **line1, *p;
	queue_object  **obj;
	
	N = BUFSIZE;
	p = 0;
	
	buf = (char *)malloc(N * sizeof (*buf));
	if (!buf) goto out;	
	
	while(1){
		c = fgetc(f);
		if ((c == EOF) || strchr('\n', c)) {
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
		line[j] = strdup(buf);
		j++;
	}	
	
	line1 = strdup(line);

	while(1){
		
	}

	free(line1);
	free(line);
out:
	return;
}

int main(void){



return 0;
}
