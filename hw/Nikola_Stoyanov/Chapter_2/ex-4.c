#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void squeeze(char s1[], char s2[]);

int main()
{
    char *s = strdup("hello world ");
    
    //Exercise 2-4. Write an alternative version of squeeze(s1,s2)
    //that deletes each character in s1 that matches any character in the string s2. 
    squeeze(s, "hello");
    printf("\n%s", s);
	return 0;
}


void squeeze(s1, s2) 
char s1[];
char s2[];
{
    int i, j, k;
    
    for(k = 0; s2[k] != '\0'; k++) {
        for (i = j = 0; s1[i] != '\0'; i++)
            if (s1[i] != s2[k])
                s1[j++] = s1[i];
        s1[j] = '\0';
    }
}


