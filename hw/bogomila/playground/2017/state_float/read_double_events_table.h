#ifndef _READ_DOUBLE_EVENTS_TABLE_ACTIVATOR_
#error Bad #include "read_double_events_table.h"
#endif

#ifndef _READ_DOUBLE_EVENTS_TABLE_GUARDIAN_
#define _READ_DOUBLE_EVENTS_TABLE_GUARDIAN_

#include "state_machine.h"

enum {
	STATE_DIGIT = 1,
	STATE_DIGIT2 = 2,
	STATE_SEPARATOR = 3,
	STATE_MINUS = 4,
	STATE_PLUS = 5,
	STATE_DOT = 6,
	STATE_END = 7
};

enum {
	EVENT_DIGIT = 1,
	EVENT_SEPARATOR = 2,
	EVENT_MINUS = 3,
	EVENT_PLUS = 4,
	EVENT_DOT = 5,
	EVENT_END = 6,
	EVENT_ANY = 7,
	EVENT_INVALID = 8
};

static event_table events[] = {
	{ STATE_DIGIT, EVENT_DIGIT, STATE_DIGIT, &digit },
	{ STATE_DIGIT, EVENT_DOT, STATE_DOT, &dot },
	
	{ STATE_DIGIT2, EVENT_DIGIT, STATE_DIGIT2, &digit2 },
	{ STATE_DIGIT2, EVENT_SEPARATOR, STATE_SEPARATOR, &end },
	
	{ STATE_SEPARATOR, EVENT_SEPARATOR, STATE_SEPARATOR, NULL },
	{ STATE_SEPARATOR, EVENT_DIGIT, STATE_DIGIT, &digit },
	{ STATE_SEPARATOR, EVENT_MINUS, STATE_MINUS, &negate },
	{ STATE_SEPARATOR, EVENT_PLUS, STATE_PLUS, &plus },
	{ STATE_SEPARATOR, EVENT_DOT, STATE_DOT, &dot },
	
	{ STATE_DOT, EVENT_DIGIT, STATE_DIGIT2, &digit2 },
	{ STATE_DOT, EVENT_SEPARATOR, STATE_END, &end },
	
	{ STATE_MINUS, EVENT_DIGIT, STATE_DIGIT, &digit },
	{ STATE_MINUS, EVENT_DOT, STATE_DOT, &dot },
	
	{ STATE_PLUS, EVENT_DIGIT, STATE_DIGIT, &digit },
	{ STATE_PLUS, EVENT_DOT, STATE_DOT, &dot },
	
	{ STATE_ANY, EVENT_ANY, STATE_ANY, &end },
	
	{ EOET, EOET, EOET, &end }
};

static const int initial_machine_state = STATE_SEPARATOR;

#endif
