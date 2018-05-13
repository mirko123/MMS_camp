#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>

#include "state_machine.h"
#include "calc_states.h"
#include "queue.h"
#include "state_machine.c"

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
		
		if ((char)ctx->c == 'p') if (GETINT(d) == -1) printf("ITS A TRAP!!!!\n"); else printf("%d\n", GETINT(d));
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

enum {
	BUFSIZE = 128
};

char *getstr(FILE *f, const char *delimiters) {
	char *buf, *t;
	int N, p;
	int c;
	
	N = BUFSIZE;
	p = 0;
	
	buf = (char *)malloc(N * sizeof (*buf));
	if (!buf) goto out;
	
	while (1) {
		c = fgetc(f);
		if ((c == EOF) || strchr(delimiters, c)) {
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
	}
out:
	return buf;
}

void *thr0(void *arg) 
{			
		state_machine st;
		calc_context ctx;
	
		ctx.stack = queue_create();
		if (!ctx.stack) 
		{
			fprintf(stderr, "out of memory\n");
		}
		init_state_machine(&st, SEPARATOR, TERM, deltas, &ctx);
	
		ctx.acc = 0;
		ctx.c = 0;
	
		FILE *f0 = (FILE *)arg;
		while(ctx.c != EOF)
		{		
			run_state_machine(&st, decode(FETCH(ctx.c, f0)));
		}
		queue_delete(ctx.stack);
		//sleep(1);//proverka dali se izpulnqvat paralelno :)))
}


int main(int argc, char *argv[], char **envp) 
{
	char *s;
	FILE *gospodi;
	FILE *boje;
	pthread_t t0;
	pthread_attr_t ta0;
	long rv0;
	pthread_attr_init(&ta0);
	gospodi = fopen(argv[1], "r");
	if(gospodi)
	{
		while (!(feof(gospodi))) 
		{
			s = getstr(gospodi, " .:;-!?()[]\n\t"); 
			if(!feof(gospodi))
			{
				printf("%s\n", s);
				boje = fopen(s, "r");
				pthread_create(&t0, &ta0, &thr0,(void *)boje);
			}
		}
		pthread_join(t0, (void **)&rv0);
		fclose(gospodi);
		fclose(boje);
	}
	else printf("Error: Can't open file or no file!!!\n");
		return 0;
}
