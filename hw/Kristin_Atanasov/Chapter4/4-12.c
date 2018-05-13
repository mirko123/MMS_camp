#include <stdio.h>
#define MAX 255
int _itoa(char s[], int n, int k)
{
     if (n < 0) {
	  s[k++] = '-';
	  n = -n;
     }

     if ( n / 10 ) {
	  k = _itoa(s, n / 10, k);
     }
     s[k++] = (n % 10) + '0';
     return k;
}

void itoa(char s[], int n)
{
    int i = _itoa (s, n, 0);
    s[i] = '\0';
    return;
}

int main(void)
{
     char s[MAX];
     itoa(s, -6565);
     printf ("-6565 converted to %s\n", s);
     return 0;
}
