#include <stdio.h>
#include <ctype.h>

unsigned long htoi(const char s[]);

int main(void)
{
        printf("0xfc1affff = %lu\n", htoi("0xfc1affff"));
        printf("0xFfFFa = %lu\n", htoi("0xFFfFa"));
        printf("0X12421 = %lu\n", htoi("0X12421"));
        printf("0xAAAB = %lu\n", htoi("0xAAAB"));
        return 0;
}
unsigned long htoi(const char s[])
{
        unsigned long n = 0;

        for (int i = 0; s[i] != '\0'; i++) {
                int c = tolower(s[i]);
                if (c == '0' && tolower(s[i+1]) == 'x')
                        i++;
                else if (c >= '0' && c <= '9')
                        n = 16 * n + (c - '0');
                else if (c >= 'a' && c <= 'f')
                        n = 16 * n + (c - 'a' + 10);
        }
        return n;
}
