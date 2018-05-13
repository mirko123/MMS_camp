#include<stdio.h>

int main(void) {
   
   int c;
   int blanks = 0;
   int tabs = 0;
   int newlines = 0;

   while( ( c = getchar()) != EOF) {
      if( c == ' ') blanks++;
      if(c == '\t') tabs++;
      if(c == '\n') newlines++;
}

    printf("%d\t%d\t%d\t\n", blanks, tabs, newlines);

    return 0;
}
      
