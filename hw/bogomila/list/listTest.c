#include <stdio.h>
#include<stdio.h>

#include "list.h"

int main(void) {
   queue q;
   list *l;
   int j;

   init_queue(&q);

  

   for(j = 0; j<16; j++)
#ifdef BEGIN
         if(!addB(&q, j)) fprintf(stderr, "cannot add%d\n", j);
#elif END
         if(!addE(&q, j)) fprintf(stderr, "cannot add%d\n", j);
/*#else
#error neither BEGIN nor END*/
#endif
#if 0 
   for(l=q.E;l;l = l->prev)
      printf("%p %p %d", l->prev, l->next, l->d);

   del_queue(queue *q);
   return 0;
}
#endif
while(detE(&q, &j))
     printf("%d\n",j);

 
  del_queue(&q);
  

return 0;

}
