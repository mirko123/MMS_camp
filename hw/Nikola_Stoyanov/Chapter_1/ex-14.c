
#include<stdio.h>
#define NUMBEROFC 128  

int main(void)
{
    int c, i, j;

    int character[NUMBEROFC];
    
    for (i=0; i < NUMBEROFC; ++i)
        character[i] = 0;
    
    while ((c=getchar()) != EOF)
        ++character[c];

    for (i=0; i < NUMBEROFC; ++i)
    {
        if (i < 33) 
            printf("%d ", i);
        else 
            printf("%c ", i);
        
        for (j=0; j < character[i]; ++j)
            putchar('*');
        
        putchar('\n');
    }
return 0;
}
