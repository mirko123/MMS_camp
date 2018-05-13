#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "state_machine.h"

enum {
	D1 = 1,
	D2 = 2,
	TERM = 3
};

enum {
	ALPHA = 1,
	SPACE = 2,
	INV = 3
};

int pred(void *_ctx, struct delta_t *d);
int callback(void *_ctx, struct delta_t *d);

delta_t deltas[] = {
	{ D1, ALPHA, D2, &pred, &callback },
	{ D1, SPACE, D1, &pred, NULL },
	{ D1, INV, D1, &pred, NULL },
	{ D1, EOF, TERM, &pred, NULL },
	
	{ D2, ALPHA, D2, &pred, &callback },
	{ D2, SPACE, D1, &pred, &callback },
	{ D2, INV, D2, &pred, NULL },
	{ D2, EOF, TERM, &pred, NULL },
	
	{ EODELTA, EODELTA, EODELTA, NULL, NULL }
};

struct cb_ctx {
	int c;
};
typedef struct cb_ctx cb_ctx;

int pred(void *_ctx, struct delta_t *d) {
	return 1;
}

int callback(void *_ctx, struct delta_t *d) {
	cb_ctx *ctx = (cb_ctx *)_ctx;
	
	if ((d->cur == D1) && (d->next = D2)) fputc(ctx->c, stdout);
	else if ((d->cur == D2) && (d->event == ALPHA) && (d->next = D2)) fputc(ctx->c, stdout);
	else if ((d->cur == D2) && (d->event == SPACE) && (d->next = D1)) fputc('\n', stdout);
	return 1;
}

int main(void) {
	state_machine s;
	cb_ctx ctx;
	int r = 0, event;
	
	init_state_machine(&s, D1, TERM, deltas, &ctx);
	while (r >= 0) {
		ctx.c = fgetc(stdin);
		if (isalpha(ctx.c)) event = ALPHA;
		else if (isspace(ctx.c)) event = SPACE;
		else if (ctx.c == EOF) event = EOF;
		else event = INV;
		r = run_state_machine(&s, event);
	}
	
	return 0;
}

