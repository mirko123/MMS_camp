#include <stdio.h>
#include <libc.h>
#include "queue/include/queue.h"

void calc(FILE *in, FILE *out, queue_object *q);
datum byHash(char* str, int *key);
int byDolar(queue_object *q, char* str);
typedef int (*functionPtr)(int);
int main(void) {
	FILE *in = fopen("file1.txt","r");
	FILE *out = fopen("file2.txt","w+");
	queue_object *q;
	calc(in,out,q);

	fclose(in);
	fclose(out);
	return 0;
}

void calc(FILE *in, FILE *out, queue_object *q) {
	long size = 8192;
	long readed;
	char c;
	char firstChar;
  	char *buffer = (char*) malloc (sizeof(char)*size);
  	char *navigator;

	// while(readed = fread (buffer,1,size,in)) {

	// }
	readed = fread (buffer,1,size,in);
	navigator = buffer;
	firstChar = *navigator;
	// if(firstChar == '#') {

	// }
	// else if(firstChar == '$') {

	// }


	// while(navigator = strchr(navigator, '\n')) {

	// }



	printf("%s\n", buffer);
	buffer[readed] = '\0';
}

datum byHash(char* str, int *key) {
	queue_object *q = queue_create();
	datum d;
	datum container;
	char *pos;
	int num;
	int counter = 0;
	int index = atoi(str + 1);



	for (pos = strchr(str,' '); pos; pos = strchr(pos,' ')) {
		num = atoi(pos);
		d.type = INT;
		d.data.i = num;
		d.on_delete = NULL;
		q->addE(q, counter, d);

		counter++;
	}

	container.type = VOIDP;
	container.data.vp = q;
	container.on_delete = NULL;
	// container.on_delete = queue_delete;

	*key = index;

	return container;
}
int byDolar(queue_object *q, char* str) {
	int key = atoi(str + 1);
	int val = atoi(strchr(str,' '));
	int himKey;
	datum d;


	queue_object* targetQueue = (queue_object*)q->search(q, key, &d);
	
	functionPtr func;
	while(q->getE(targetQueue, &himKey, &d)) {
		func = d.data.vp;
		val = (*func)(val);
	}

	return val;
}














