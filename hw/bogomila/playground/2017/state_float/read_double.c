#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#include "state_machine.h"
#include "read_double.h"

static int digit(void *_ctx, int cur_state, int event, int next_state);
static int negate(void *_ctx, int cur_state, int event, int next_state);
static int plus(void *_ctx, int cur_state, int event, int next_state);
static int digit2(void *_ctx, int cur_state, int event, int next_state);
static int dot(void *_ctx, int cur_state, int event, int next_state);
static int end(void *_ctx, int cur_state, int event, int next_state);

#define _READ_DOUBLE_EVENTS_TABLE_ACTIVATOR_
#include "read_double_events_table.h"

static int digit(void *_ctx, int cur_state, int event, int next_state) {
	callback_ctx *ctx = (callback_ctx *)_ctx;
	char buf[2];
	
	buf[0] = (char)(ctx->symbol & 0xff);
	buf[1] = '\0';
	ctx->accumulator = ctx->accumulator * 10.0 + (double)(atoi(buf));
	
	return 1;
}

static int digit2(void *_ctx, int cur_state, int event, int next_state) {
	callback_ctx *ctx = (callback_ctx *)_ctx;
	char buf[2];
	
	buf[0] = (char)(ctx->symbol & 0xff);
	buf[1] = '\0';
	ctx->accumulator += (double)(atoi(buf)) * pow(10.0, (double)ctx->power);
	ctx->power--;
	
	return 1;
}

static int dot(void *_ctx, int cur_state, int event, int next_state) {
	callback_ctx *ctx = (callback_ctx *)_ctx;
	
	ctx->power = -1;
	
	return 1;
}

static int end(void *_ctx, int cur_state, int event, int next_state) {
	callback_ctx *ctx = (callback_ctx *)_ctx;
	
	if (ctx->negate) ctx->accumulator = -ctx->accumulator;
	printf("END: %lf\n", ctx->accumulator);
	
	return 0;
}

static int negate(void *_ctx, int cur_state, int event, int next_state) {
	callback_ctx *ctx = (callback_ctx *)_ctx;
	
	ctx->negate = 1;
	
	return 1;
}

static int plus(void *_ctx, int cur_state, int event, int next_state) {
	callback_ctx *ctx = (callback_ctx *)_ctx;
	int r = 1;
	
	ctx->negate = 0;
	
	return 1;
}

void do_read_double(void) {
	state_machine m;
	callback_ctx ctx;
	int event;
	
	ctx.accumulator = 0;
	ctx.negate = 0;
	ctx.power = 0;

	init_state_machine(&m, initial_machine_state, events, &ctx);
	
	while ((ctx.symbol = fgetc(stdin)) != EOF) {
		if (isdigit(ctx.symbol)) event = EVENT_DIGIT;
		else if ((ctx.symbol == (int)'\n') || (ctx.symbol == (int)' ')) event = EVENT_SEPARATOR;
		else if (ctx.symbol == (int)'-') event = EVENT_MINUS;
		else if (ctx.symbol == (int)'+') event = EVENT_PLUS;
		else if (ctx.symbol == (int)'.') event = EVENT_DOT;
		else event = EVENT_SEPARATOR;
		if (!run_state_machine(&m, event)) break;
	}

	return;
}

int main(void) {
	do_read_double();
	
	return 0;
}

