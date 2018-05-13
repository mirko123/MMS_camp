#ifndef _READ_DOUBLE_
#define _READ_DOUBLE_

struct callback_ctx {
	int symbol;
	double accumulator;
	int negate;
	int power;
};
typedef struct callback_ctx callback_ctx;

#endif
