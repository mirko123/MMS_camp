#include<stdlib.h>

#include "list.h"

void init_queue(queue *q) {
     q->B = q->E =NULL;
     return;
}

void del_queue(queue *q) {
     list *l, *t;

     l = q->B;
     
     while(l) {
          t = l;
          l = l->next;
          free(t);
       }
 
     init_queue(q);//prosto kazva na B i E da sa NULL

     return;
}

int addB( queue *q, int key, datum d) {
    list *l;

    l = malloc(sizeof(list));//l=(list*)calloc(1,sizeof(list))
    if(!l) return 0;

    l->d = d;
    l->prev =NULL;//ne sa nujni kogato polzvame callpoc, zashtoto calloca gi null-va po podrazbirane

    if (q->B) {
              l->next = q->B;
              q->B->prev=l;
              q->B = l;
} else {
     l->next =NULL;
     q->B = q->E = l;
    }
    return 1;
}

int addE( queue *q, int key, datum d) {
    list *l;

    l = malloc(sizeof(list));//l=(list*)calloc(1,sizeof(list))
    if(!l) return 0;

    l->d = d;
    l->next =NULL;

    if (q->E) {

              l->next = q->E;
              q->E->next = l;
              q->E = l;
} else {
     l->prev =NULL;
     q->B = q->E = l;
    }

    return 1;
}

int getB(queue *q,int *key, datum *d) {
     list *l;
     if(!q->B) return 0;
   
     l= q->B;
     if(l->next){//nachalniqt ni element ima sledvasht
        q->B= l->next;
        q->B->prev = NULL;
       
        }else init_queue(q);

       *d =l->d;
       free(l);

      return 1;

}
int getE(queue *q,int *key, datum *d) {
     list *l;
     if(!q->E) return 0;
   
     l= q->E;
     if(l->prev){//nachalniqt ni element ima predishen
        q->E= l->prev;
        q->E->next = NULL;
       
        }else init_queue(q);

       *d =l->d;
       free(l);

      return 1;

}































