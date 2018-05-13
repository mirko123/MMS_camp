#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"
#include "func.h"
#include "getstr.h"
#include "calc.h"

#if 0
#define TRACE stdout
#endif

static void on_delete(datum *d) {
#ifdef TRACE
	fprintf(TRACE, "%s:%d:%s>\t%p\n", __FILE__, __LINE__, __FUNCTION__, d->data.vp);
#endif
	queue_delete((queue_object *)d->data.vp);
	return;
}

static void define(char *line, queue_object *compositions, queue_object *functions) {
	char *p, j;
	queue_object *comp = NULL;
	datum d;
	int ckey;
	int key;
	
	for (j = 0, p = strtok(line, " "); p; p = strtok(NULL, " "), j++) {
		if (!j) {
			p[0] = ' ';
			if ((ckey = atoi(p)) < 0) break;
			if (!(comp = queue_create())) break;
#ifdef TRACE
			fprintf(TRACE, "%s:%d:%s>\t%d %p\n", __FILE__, __LINE__, __FUNCTION__, ckey, comp);
#endif
		} else {
			if ((key = atoi(p)) < 0) break;
#ifdef TRACE
			fprintf(TRACE, "%s:%d:%s>\t\t%d\n", __FILE__, __LINE__, __FUNCTION__, key);
#endif
			if (functions->search(functions, key, &d)) {
#ifdef TRACE
				fprintf(TRACE, "%s:%d:%s>\t\t\t%p\n", __FILE__, __LINE__, __FUNCTION__, d.data.vp);
#endif
				if (!comp->addE(comp, key, d)) break;
			}
		}
	}
	
	if (comp) {
		d.type = VOIDP;
		d.data.vp = comp;
		d.on_delete = &on_delete;
		if (!compositions->addE(compositions, ckey, d)) {
			queue_delete(comp);
		}
	}
	
	return;
}

static void compute(FILE *out, char *line, queue_object *compositions) {
	char *p, j;
	queue_object *comp;
	datum d;
	int key, ckey;
	int val, acc;
	void *iter;
	int valid;
	F function;
	
	for (j = 0, p = strtok(line, " "); p; p = strtok(NULL, " "), j++) {
		if (!j) {
			p[0] = ' ';
			if ((ckey = atoi(p)) < 0) break;
		} else if (j) {
			val = atoi(p);
			acc = val;
#ifdef TRACE
			fprintf(TRACE, "%s:%d:%s>\t%d %d\n", __FILE__, __LINE__, __FUNCTION__, ckey, val);
#endif
			if (compositions->search(compositions, ckey, &d)) {
				if (d.type != VOIDP) break;
#ifdef TRACE
				fprintf(TRACE, "%s:%d:%s>\t\t%p\n", __FILE__, __LINE__, __FUNCTION__, d.data.vp);
#endif
				comp = (queue_object *)d.data.vp;
				iter = comp->iterE(comp, NULL, &key, &d, &valid);
				if ((!iter) && (!valid)) {
#ifdef TRACE
					fprintf(TRACE, "%s:%d:%s>\t\t\t%p %d\n", __FILE__, __LINE__, __FUNCTION__, iter, key);
#endif
					fprintf(out, "$%d(%d) %d\n", ckey, val, acc);
#ifdef TRACE
					fprintf(TRACE, "%s:%d:%s>\tTERM\t\t\t%p %d\n", __FILE__, __LINE__, __FUNCTION__, iter, key);
#endif
				} else while (1) {
#ifdef TRACE
					fprintf(TRACE, "%s:%d:%s>\t\t\t%p %d\n", __FILE__, __LINE__, __FUNCTION__, iter, key);
#endif
					if (d.type != VOIDP) {
						fprintf(out, "$%d(%d) %d\n", ckey, val, acc);
						break;
					}
					function = (F)d.data.vp;
					acc = function(acc);
					if (!iter) {
						fprintf(out, "$%d(%d) %d\n", ckey, val, acc);
						break;
					}
					iter = comp->iterE(comp, iter, &key, &d, &valid);
				}
			}
			break;
		}
	}
	
	return;
}

void calc(FILE *in, FILE *out, queue_object *functions) {
	queue_object *compositions;
	char *line;
	
	if (!(compositions = queue_create())) return;
	
	while (!feof(in)) {
		if (!(line = getstr(in, "\n"))) break;
#ifdef TRACE
		fprintf(TRACE, "%s:%d:%s>\t%s\n", __FILE__, __LINE__, __FUNCTION__, line);
#endif
		if (!strlen(line)) {
			free(line);
			continue;
		}
		
		switch (line[0]) {
		case '#':
			define(line, compositions, functions);
			break;
		case '$':
			compute(out, line, compositions);
			break;
		}
		
		free(line);
	}
	
	queue_delete(compositions);
	
	return;
}

