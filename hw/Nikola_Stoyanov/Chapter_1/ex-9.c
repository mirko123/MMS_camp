#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void remove_extra_spaces(char *formatted_string, char *string);

int main()
{
    // Exercise 1-9. Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank. 
    char *string = "hello         world  it`s me  ";
    char formatted_string[sizeof(string)];
    remove_extra_spaces(formatted_string, string);
    
    printf("\nOriginal string = %s\nFormatted string = %s\n", string, formatted_string);
    
    return 1;
}

void remove_extra_spaces(char *formatted_string, char *string)
{
    while (*string) {
        if (*(formatted_string - 1 ) == ' ' && *string == ' ') 
            string++;
        else {
            *(formatted_string++) = *(string++);
        }
    }
    *formatted_string = '\0';
}


