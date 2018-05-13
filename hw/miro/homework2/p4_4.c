#include <stdio.h>
#include <libc.h>
#include <string.h>

#define MAXVAL 100 /* maximum depth of val stack */
int sp = 0; /* next free stack position */ 
double val[MAXVAL]; /* value stack */
/* push: push f onto value stack */ 
void push(double f)
{
   	if (sp < MAXVAL)
   		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}
/* pop: pop and return top value from stack */ 
double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n"); return 0.0;
	} 
}

void clear(void) {
	memset(val, 0, MAXVAL*sizeof(int));
	sp = 0;
}

void printTop() {
	printf("%f\n",val[sp - 1]);
}

void duplicateTop() {
	double temp;
	if (sp > 0){
		temp = pop();
		push(temp);
		push(temp);
	}
	else {
		printf("error: stack empty\n");
	} 
}

void swatTopElements(void) {
	double temp;
	if (sp >= 2){
		temp = val[sp - 2];
		val[sp - 2] = val[sp - 1];
		val[sp - 1] = temp;
	}
	else {
		printf("error: stack size < 2 \n");
	} 
}

int main(int argc, char* argv[]) {
	push(2.3);
	push(2.5);
	printTop();
	swatTopElements();
	printTop();
	return 0;
}

