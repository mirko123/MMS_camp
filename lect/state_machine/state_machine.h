#ifndef _STATE_MACHINE_
#define _STATE_MACHINE_

enum {
	ANYSTATE = -1,
	EODELTA = -2
};

struct delta_t;
/*
	predicate:
	returns 0 if the delta function should be ignored or non-zero (logic true)
*/
typedef int (*pred_t)(void *_ctx, struct delta_t *);
/*
	callback:
	returns 0 should the machine remain in its current state,
	1 if jump should occur, and negative in case of a run-time error
*/
typedef int (*callback_t)(void *_ctx, struct delta_t *);

struct delta_t {
	int cur;
	int event;
	int next;
	pred_t pred;
	callback_t callback;
};
typedef struct delta_t delta_t;

struct state_machine {
	int cur;
	int T;
	delta_t *deltas;
	void *_ctx;
};
typedef struct state_machine state_machine;

void init_state_machine(state_machine *sm, int S, int T, delta_t *deltas, void *_ctx);
int run_state_machine(state_machine *sm, int event);

#endif
