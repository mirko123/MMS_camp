#include <stdio.h>
#include <stdlib.h>

int any(char s1[], char s2[]);

int main()
{
    int position;
    char *string = "find my position";
    //Exercise 2-5. Write the function any(s1,s2), which returns the first location
    //in a string s1 where any character from the string s2 occurs, or -1 if s1 
    //contains no characters from s2. (The standard library function strpbrk does 
    //the same job but returns a pointer to the location.) 
    position = any(string, "mmmm");
    printf("position = %d character at pos = %c", position, string[position]);
    return 0;
}

int any(s1, s2) 
char s1[];
char s2[];
{
    int i, k;
    for (i = 0; s1[i] != '\0'; i++)
        for (k = 0; s2[k] != '\0'; k++) 
            if (s1[i] == s2[k]) return i;
    return -1;
}


