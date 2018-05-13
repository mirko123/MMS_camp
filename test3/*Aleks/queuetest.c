#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"

void on_delete_cp(datum *d) {
	printf("on_delete char pointer called\n");
	if (d->type == CHARP) free(d->data.cp);
	return;
}

int main(void) {
	char *str = "test string";
	queue_object *obj;
	datum d;
	int j, key;
	void *l;
	
	srand(0xa738c92fu);
	
	obj = queue_create();
	if (!obj) return 1;
	
	for (j = 0; j < 32; j++) {
		if (rand() & 1) {
			d.type = CHARP;
			d.data.cp = strdup(str);
			d.on_delete = &on_delete_cp;
		} else {
			d.type = INT;
			d.data.i = rand();
			d.on_delete = NULL;
		}
		obj->addE(obj, j, d);
	}
	
	for (
			l = obj->iterE(obj, NULL, &key, &d);
			l;
			l = obj->iterE(obj, l, &key, &d)) {
		printf("iter %p key %d data ", l, key);
		switch (d.type) {
		case INT:
			printf("%d\n", d.data.i);
			break;
		case CHARP:
			printf("%s\n", d.data.cp);
			break;
		default:
			printf("unknown\n");
		}
	}
	
	l = obj->search(obj, 0, &d);
	if (l) {
		for (j = 32; j < 64; j++) {
			if (rand() & 1) {
				d.type = CHARP;
				d.data.cp = strdup(str);
				d.on_delete = &on_delete_cp;
			} else {
				d.type = INT;
				d.data.i = rand();
				d.on_delete = NULL;
			}
			if (!(l = obj->addL(obj, l, j, d))) break;
		}
	}
	l = obj->search(obj, 31, &d);
	if (l) {
		for (j = 64; j < 80; j++) {
			if (rand() & 1) {
				d.type = CHARP;
				d.data.cp = strdup(str);
				d.on_delete = &on_delete_cp;
			} else {
				d.type = INT;
				d.data.i = rand();
				d.on_delete = NULL;
			}
			if (!(l = obj->addR(obj, l, j, d))) break;
		}
	}
	
	for (j = 0; j < 100; j++)
		if (obj->search(obj, j, &d)) {
			printf("found key %d data ", j);
			switch (d.type) {
			case INT:
				printf("%d\n", d.data.i);
				break;
			case CHARP:
				printf("%s\n", d.data.cp);
				break;
			default:
				printf("unknown\n");
			}
		}
	
	for (j = 0; j < 100; j++)
		if (l = obj->search(obj, j, &d)) {
			printf("found key %d; ", j);
			if (!(j % 3)) {
				printf("delete key %d\n", j);
				obj->del(obj, l);
			} else printf("do nothing\n");
		}
	
	for (
			l = obj->iterE(obj, NULL, &key, &d);
			l;
			l = obj->iterE(obj, l, &key, &d)) {
		printf("iter %p key %d data ", l, key);
		switch (d.type) {
		case INT:
			printf("%d\n", d.data.i);
			break;
		case CHARP:
			printf("%s\n", d.data.cp);
			break;
		default:
			printf("unknown\n");
		}
	}
	
	queue_delete(obj);
	
	return 0;
}

