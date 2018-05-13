#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
#include "test.h"
#include "queue.c"

void calc(FILE *in, FILE *out, queue_object *q);


int main(void) {
	char *s;
	queue_object *l;
	l = queue_create();
	
	calc(stdin,stdout,l);
	
	return 0;
}
