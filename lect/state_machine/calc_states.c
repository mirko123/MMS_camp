#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "queue.h"
#include "state_machine.h"

#include "calc_states.h"

#define SETINT(D, V) do { \
	(D).type = INT; \
	(D).data.i = (V); \
	(D).on_delete = NULL; \
} while (0)

#define GETINT(D) ((D).data.i)

#define FETCH(C, STREAM) ((C) = fgetc((STREAM)))

typedef struct calc_context {
	queue_object *stack;
	int acc;
	int c;
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

static int decode(int c) {
	if (c == EOF) return END;
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

int main(void) {
	state_machine st;
	calc_context ctx;
	
	ctx.stack = queue_create();
	if (!ctx.stack) {
		fprintf(stderr, "out of memory\n");
		return 1;
	}
	init_state_machine(&st, SEPARATOR, TERM, deltas, &ctx);
	
	ctx.acc = 0;
	ctx.c = 0;
	
	while (run_state_machine(&st, decode(FETCH(ctx.c, stdin))) >= 0);
	
	queue_delete(ctx.stack);
	
	return 0;
}

