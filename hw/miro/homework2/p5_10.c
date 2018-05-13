#include <stdio.h>
#include <libc.h>
#include <string.h>
// #include "queue/include/queue.h"
#include "queue.h"

int isNumber(char *str);

int main(int argc, char* argv[]) {
	char *expr = strdup("2 3 4 + *");
	char *navigator = expr;
	int number;
	char operator;
	int operand1;
	int operand2;
	int result;
	int j, key;
	void *l;
	queue_object *queue;
	datum d;
	d.type = INT;
	d.data.i = 1;
	d.on_delete = NULL;
	queue = queue_create();

	while(navigator && *navigator) {
		if(isNumber(navigator)) {
			number = atoi(navigator);
			d.data.i = number;
			addE(queue,key, d);
			navigator = strchr(navigator,' ');
		}
		else {
			operator = *navigator;
			getE(queue,&key,&d);
			operand1 = d.data.i;
			getE(queue,&key,&d);
			operand2 = d.data.i;
			navigator = strchr(navigator,' ');

			switch(operator) {
				case '*':
					number = operand1 * operand2;
					break;
				case '+':
					number = operand1 + operand2;
					break;
				case '-':
					number = operand1 - operand2;
					break;
			}
			d.data.i = number;
			addE(queue,key,d);
		}
	}

	getE(queue,&key,&d);
	printf("%d\n", d.data.i);

	return 0;
}

int isNumber(char *str) {
	return '0'<= *str && *str <= '9'?1:0;
}