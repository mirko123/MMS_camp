#include <stdio.h>
#include <stdlib.h>

#include "queue.h"
#include "calc.h"

static int f0(int a) {
	return a * 2;
}

static int f1(int a) {
	return a * 3;
}

static int f2(int a) {
	return a + 1;
}

static int f3(int a) {
	return a + 7;
}

static int f4(int a) {
	return a / 2;
}

int main(void) {
	queue_object *functions;
	datum d;
	functions = queue_create();
	
	d.type = VOIDP;
	d.on_delete = NULL;
	
	d.data.vp = (void *)&f0;
	functions->addE(functions, 0, d);
	d.data.vp = (void *)&f1;
	functions->addE(functions, 1, d);
	d.data.vp = (void *)&f2;
	functions->addE(functions, 2, d);
	d.data.vp = (void *)&f3;
	functions->addE(functions, 3, d);
	d.data.vp = (void *)&f4;
	functions->addE(functions, 4, d);
	
	calc(stdin, stdout, functions);
	
	queue_delete(functions);

	return 0;
}

