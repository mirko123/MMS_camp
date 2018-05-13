#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"

void calc(FILE *in, FILE *out, queue_object *q);

int main(void) 
{
	queue_object *obj;
	datum d;	
	obj = queue_create();

	calc(stdin, stdout, obj);
	return 0;
}

void calc(FILE *file, FILE *out, queue_object *q)
{
	char c;
	int mode = 0;
	char *inputLine = (char*)malloc(80);
	char *input;

	c = getchar();
	if (c == '#') 
		mode = 0;
	else if (c == '$') 
		mode = 1;
	else {
		fprintf(stderr, "Invalid input");
		return;	
	}
	
	if (mode == 0) {// define composition #	
    		fgets(inputLine, 80, stdin);
    		input = strtok(inputLine, " ");
		printf("%s\n", input);
		input = strtok(NULL, " ");
		printf("%s\n", input);
		input = strtok(NULL, " ");
		printf("%s\n", input);
	} else if ( mode == 1) { // compute composition $

	}
	return;
}








