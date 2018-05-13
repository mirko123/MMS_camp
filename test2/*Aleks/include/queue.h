#ifndef _QUEUE_H_
#define _QUEUE_H_

enum datatype {
	CHAR,
	UCHAR,
	SHORT,
	USHORT,
	INT,
	UINT,
	LONG,
	ULONG,
	VOIDP,
	CHARP
};
typedef enum datatype datatype;

union datastore {
	char c;
	unsigned char uc;
	short s;
	unsigned short us;
	int i;
	unsigned int ui;
	long l;
	unsigned long ul;
	void *vp;
	char *cp;
};
typedef union datastore datastore;

struct datum;
typedef void (*on_delete_f)(struct datum *);

struct datum {
	datatype type;
	datastore data;
	on_delete_f on_delete;
};
typedef struct datum datum;

struct queue_object;
typedef int (*queue_adder)(struct queue_object *, int, datum);
typedef void *(*queue_adder_pos)(struct queue_object *, void *, int, datum);
typedef int (*queue_getter)(struct queue_object *, int *, datum *);
typedef void *(*queue_search)(struct queue_object *, int, datum *);
typedef void (*queue_del)(struct queue_object *, void *);
typedef void *(*queue_iterator)(struct queue_object *, void *, int *, datum *);

struct queue_object {
	void *queue;
	queue_adder addB;
	queue_adder addE;
	queue_adder_pos addL;
	queue_adder_pos addR;
	queue_getter getB;
	queue_getter getE;
	queue_search search;
	queue_del del;
	queue_iterator iterB;
	queue_iterator iterE;
};
typedef struct queue_object queue_object;

queue_object *queue_create(void);
void queue_delete(queue_object *);

#endif
