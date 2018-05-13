#include<stdio.h>

int main(void)
{
  int c,last;

  last=-1;

  while((c=getchar())!=EOF)
  {
    if(c==' ')
    {
        if(last!=' ')
            putchar(c);
    }
    else
        putchar(c);

    last=c;
  }
return 0;
}
