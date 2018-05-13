#include <stdio.h>
/* copy input to output; 1st version */
main()
{
    int c;
    c = getchar() != EOF;

    printf("%d\n", c); // = 1;
    return 0;
}
