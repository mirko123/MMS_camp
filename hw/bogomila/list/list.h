#ifndef _LIST_H_
#define _LIST_H_

enum datatype {
     INT,
     UINT,
     LONG,
     ULONG,
     VOIDP,
     CHARP
};
typedef enum datatype datatype;

union data {// ili shte e 4 ili 8 zavisi ot os 32/64
     int i;
     unsigned int uil
     long l;
     unsigned long ul;
     void *vp;
     char *cp;
};
typedef union data data;

struct datum {
     datatype type;
     data d;
}
typedef struct datum datum;

     

struct list {
      int key;
       datum d;
      struct list *prev, *next;
};
typedef struct list list;

struct queue {

      list *B, *E;
};
typedef struct queue queue; 

void init_queue(queue *q);
void del_queue(queue *q);
int addB( queue *q,int key, datum d);
int addE( queue *q,int key, datum d);
int getB(queue *q,int *key,datum *d);
int getE(queue *q,int *key,datum *d);

#endif
