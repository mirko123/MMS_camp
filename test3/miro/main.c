#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <pthread.h>

#include "queue/include/queue.h"
#include "state_machine/state_machine.h"
#include "state_machine/calc_states.h"

#define SETINT(D, V) do { \
	(D).type = INT; \
	(D).data.i = (V); \
	(D).on_delete = NULL; \
} while (0)

#define GETINT(D) ((D).data.i)

#define FETCH(C, STREAM) ((C) = fgetc((STREAM)))

int counter = 0;

void remove_newline_ch(char *line);

void remove_newline_ch(char *line)
{
	char *navigator = line;
    while(navigator[0] != EOF && navigator[0] != '\0') {
    	if(navigator[0] == '\n') navigator[0] = ' '; 
    	navigator++;
    }
}

typedef struct calc_context {
	queue_object *stack;
	int acc;
	int c;
	char *expr;
} calc_context;

static int callback_digit(void *_ctx, struct delta_t *delta) {
	calc_context *ctx = (calc_context *)_ctx;
	char str[2] = { '\0', '\0' };
	
	if (delta->cur != NUMBER) ctx->acc = 0;
	str[0] = (char)ctx->c;
	ctx->acc *= 10;
	ctx->acc += atoi(str);
	return 1;
}

static int callback_sep(void *_ctx, struct delta_t *delta) {
	calc_context *ctx = (calc_context *)_ctx;
	datum d;
	int r = 1;
	
	if (delta->cur == NUMBER) {
		SETINT(d, ctx->acc);
		if (!ctx->stack->addE(ctx->stack, 0, d)) {
			fprintf(stderr, "cannot push\n");
			r = -1;
		}
	}
	
	return r;
}

static int callback_op(void *_ctx, struct delta_t *delta) {
	calc_context *ctx = (calc_context *)_ctx;
	int left, right, result;
	int key;
	datum d;
	int r = 1;
	
	if (delta->cur == NUMBER) {
		SETINT(d, ctx->acc);
		if (!ctx->stack->addE(ctx->stack, 0, d)) {
			fprintf(stderr, "cannot push\n");
			r = -1;
			goto out;
		}
	}
	
	switch ((char)ctx->c) {
	case 'p': 
		if(!ctx->stack->getE(ctx->stack, &key, &d)){
			printf("cannot pop\n");
		}

		if(!ctx->stack->addE(ctx->stack, key, d)){
			printf("cannot push\n");
		}

		result = GETINT(d);	
		if(result < 0) printf("result: %d    Expr: %s    \t\t\tIT'S A TRAP!!!\n", result, ctx->expr);
		else printf("result: %d    Expr: %s\n", result, ctx->expr);

		break;
	case '~':
		if (!ctx->stack->getE(ctx->stack, NULL, &d)) {
			fprintf(stderr, "cannot pop\n");
			r = 1;
			break;
		}
		
		if ((char)ctx->c == 'p') printf("%d\n", GETINT(d));
		else {
			GETINT(d) = ~GETINT(d);
			if (!ctx->stack->addE(ctx->stack, 0, d)) {
				fprintf(stderr, "cannot push\n");
				r = -1;
			}
		}
		
		break;
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case '&':
	case '|':
	case '^':
		if (!ctx->stack->getE(ctx->stack, NULL, &d)) {
			fprintf(stderr, "cannot pop\n");
			r = 1;
			break;
		} else right = GETINT(d);
		
		if (!ctx->stack->getE(ctx->stack, NULL, &d)) {
			fprintf(stderr, "cannot pop\n");
			if (!ctx->stack->addE(ctx->stack, 0, d)) {
				fprintf(stderr, "cannot push\n");
				r = -1;
			} else r = 1;
			break;
		} else left = GETINT(d);
		
		if ((char)ctx->c == '+') result = left + right;
		else if ((char)ctx->c == '-') result = left - right;
		else if ((char)ctx->c == '*') result = left * right;
		else if ((char)ctx->c == '/') result = left / right;
		else if ((char)ctx->c == '%') result = left % right;
		else if ((char)ctx->c == '&') result = left & right;
		else if ((char)ctx->c == '|') result = left | right;
		else if ((char)ctx->c == '^') result = left ^ right;
		
		SETINT(d, result);
		if (!ctx->stack->addE(ctx->stack, 0, d)) {
			fprintf(stderr, "cannot push\n");
			r = -1;
		}
		
		break;
	}
out:
	return r;
}


static int callback_end(void *_ctx, struct delta_t *delta) {
	calc_context *ctx = (calc_context *)_ctx;
	datum d;
	int result = 1;
	
	// ctx->stack->getE(ctx->stack, NULL, &d);
	// result = GETINT(d);
	// printf("%d\n", result);
	return result;
}

static int decode(int c) {
	if (c == EOF || c == '\n' || c == '\0') return END;
	else if (isdigit(c)) return DIGIT;
	else if (
			(c == '+') || (c == '-')
		||
			(c == '*') || (c == '/') || (c == '%')
		||
			(c == '&') || (c == '|') || (c == '^')
		||
			(c == '~')
		||
			(c == 'p')
	) return OP;
	else return SEP;
}

static int calculate(char *input) {
	state_machine st;
	calc_context ctx;
	int length;
	int i;
	int j;
	datum d;
	int result = 1;
	
	ctx.stack = queue_create();
	if (!ctx.stack) {
		fprintf(stderr, "out of memory\n");
		return 1;
	}
	init_state_machine(&st, SEPARATOR, TERM, deltas, &ctx);
	
	ctx.acc = 0;
	ctx.c = 0;
	ctx.expr = input;
	
	// while (run_state_machine(&st, decode(FETCH(ctx.c, stdin))) >= 0);

	for(i = 0, length = strlen(input); i < length; i++) {
		ctx.c = input[i];
		run_state_machine(&st, decode(ctx.c));
	}

	ctx.stack->getE(ctx.stack, &j, &d);
	ctx.stack->addE(ctx.stack, j,d);
	result = GETINT(d);
	// printf("ress:   %d\n", result);
	// printf("Expr: %s\n", input);

	
	// queue_delete(ctx.stack);
	
	return result;
}





void *worker(void *arg) {
	queue_object *q = (queue_object *)arg;
	datum d;
	int arraySize = 1024;
	char *expr = (char*)malloc(arraySize*sizeof(char));
	char *navigator = expr;
	FILE* file;
	int j, k;
	int result;

	if(!q->getE(q, NULL, &d)) {
		printf("cant pop \n");
		return NULL;
	}
	file = fopen(d.data.cp, "r");

    while ((*navigator = getc(file)) != EOF) {
    	navigator++;
    }
    *navigator = '\0';

    remove_newline_ch(expr);
    // printf("Expr: %s\n", expr);
    result = calculate(expr);
    // if(result < 0) printf("IT'S A TRAP!!!\n");
	// else printf("result: %d\n", result);
    // printf("Expr: %s   result: %d\n", expr,result);
    // fflush(stdout);


	// if(q->getB(q, NULL, &d)) {
	// 	// printf("%s\n", d.data.cp);
	// 	calculate(d.data.cp);
	// }

	fclose(file);
	
	return NULL;
}

int main(int argc, char *argv[]) {
	// // char *str = strdup("1 ~ 2 ~ | ~ 3 & ~ p");
	// char *str = strdup("1 2 + p");
	// remove_newline_ch(str);
	// // printf("%s\n", str);
	// int res = calculate(str);
	// // printf("%d\n", res);
	// return 0;

	queue_object *q;
	pthread_t *thr;
	pthread_attr_t ta;
	datum d;
	int nameSize;
	int j;
	// int counter = 0;
	int arraySize = 256;
	char *fileWithNames = argv[1];
	q = queue_create();

	FILE* file = fopen(fileWithNames, "r");
	char *name = (char*)malloc(arraySize*sizeof(char));

	d.type = CHARP;
	d.data.cp = NULL;
	while (fgets(name, arraySize, file)) {
		// printf("name: %s", name); 
		d.data.cp = name;
		nameSize = strlen(name);
		if(!q->addE(q, counter, d)) {
			printf("cant push\n");
			break;
		}

		if(name[nameSize - 1] != '\n') {
			name[nameSize]  = '\0';
			break;
		}
		else {
			name[nameSize - 1] = '\0';
		}
		name = (char*)malloc(arraySize*sizeof(char));
		counter++;
	}
	thr = (pthread_t*)malloc(counter*sizeof(pthread_t));

	pthread_attr_init(&ta);
	
	for (j = 0; j < counter; j++)
		pthread_create(&thr[j], &ta, &worker, q);
	
	for (j = 0; j < counter; j++)
		pthread_join(thr[j], NULL);
	
	// queue_delete(q);
	
	fclose(file);
	return 0;
}


