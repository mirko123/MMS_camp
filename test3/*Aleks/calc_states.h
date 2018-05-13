#ifdef _CALC_STATES_
#error calc_states.h included
#else
#define _CALC_STATES_
#endif

/* states */
enum {
	NUMBER = 0,
	SEPARATOR = 1,
	OPERATOR = 2,
	TERM = 3
};

/* events */
enum {
	END = -1,
	DIGIT = 0,
	SEP = 1,
	OP = 2
};

static int callback_digit(void *_ctx, struct delta_t *);
static int callback_sep(void *_ctx, struct delta_t *);
static int callback_op(void *_ctx, struct delta_t *);

static delta_t deltas[] = {
/* deltas from SEPARATOR state */
	{ SEPARATOR, DIGIT, NUMBER, NULL, &callback_digit },
	{ SEPARATOR, OP, OPERATOR, NULL, &callback_op },
	{ SEPARATOR, SEP, SEPARATOR, NULL, NULL },

/* deltas from NUMBER state */
	{ NUMBER, DIGIT, NUMBER, NULL, &callback_digit },
	{ NUMBER, OP, OPERATOR, NULL, &callback_op },
	{ NUMBER, SEP, SEPARATOR, NULL, &callback_sep },

/* deltas from OPERATOR state */
	{ OPERATOR, DIGIT, NUMBER, NULL, &callback_digit },
	{ OPERATOR, OP, OPERATOR, NULL, &callback_op },
	{ OPERATOR, SEP, SEPARATOR, NULL, NULL },

/* ANYSTATE */
	{ ANYSTATE, END, TERM, NULL, NULL },

	{ EODELTA, EODELTA, EODELTA, NULL, NULL }
};
