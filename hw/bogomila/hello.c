#include <stdio.h>
/*
void world(void){
     printf("world\n");
     return;
}

int main(void){
    printf("Hello world\n");
    world();
    return 0;
}*/

int main(void)
{
  int i;
  int sum;
  int acm;
  
  i=1;
  sum=0;
  acm=0;

  while(i<101){
    if(!(i%2)) 
   sum+=i;
    else
   acm+=i;

   i++;
         
   }

   printf("%d\t%d\n",sum, acm);

  return 0;

}
