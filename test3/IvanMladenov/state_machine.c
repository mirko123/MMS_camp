#include "state_machine.h"

void init_state_machine(state_machine *sm, int S, int T, delta_t *deltas, void *_ctx) {
	sm->cur = S;
	sm->T = T;
	sm->deltas = deltas;
	sm->_ctx = _ctx;
	
	return;
}

int run_state_machine(state_machine *sm, int event) {
	int j, r = 0;
	
	if (sm->cur == sm->T) return -1;
	
	for (j = 0; sm->deltas[j].cur != EODELTA; j++)
		if (
				((sm->deltas[j].cur == sm->cur) &&
				(sm->deltas[j].event == event))
			||
				((sm->deltas[j].cur == ANYSTATE) &&
				(sm->deltas[j].event == event))
		) {
			if (sm->deltas[j].pred) {
				if (!sm->deltas[j].pred(sm->_ctx, sm->deltas + j)) continue;
			}
			if (sm->deltas[j].callback) r = sm->deltas[j].callback(sm->_ctx, sm->deltas + j);
			else r = 1;
			break;
		}
	
	if (r > 0) sm->cur = sm->deltas[j].next;
	else if (r < 0) sm->cur = sm->T;
	
	if (sm->cur == sm->T) return -1;
	else return r;
}
