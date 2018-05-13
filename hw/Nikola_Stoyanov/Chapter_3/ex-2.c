#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void escape (char s[], char t[]);
void real (char s[], char t[]);

int main(void) 
{
    // Exercise 3-2. Write a function escape(s,t) that converts characters like newline and 
    // tab into visible escape sequences like \n and \t as it copies the string t to s. 
    // Use a switch. Write a function for the other direction as well, 
    // converting escape sequences into the real characters.
    char string[] = "this string\\t\t is to be modified \n with visible escape sequences       .";
    char visible_escape[strlen(string)*2];
    char real_characters[strlen(string)*2];
    printf("Original string: %s\n\n", string);
    escape(string, visible_escape);
    printf("Visible escapes: %s\n\n", visible_escape);
    real(visible_escape, real_characters);
    printf("Real characters: %s\n\n", real_characters);
    return 1;
}

void escape(s, t)
char s[], t[];
{
    
    while(*s != '\0') {
        switch(*s) {
            case '\n':
                *(t++) = '\\';
                *(t++) = 'n';
                break;
            case '\t':
                *(t++) = '\\';
                *(t++) = 't';
                break;
            default:
                *(t++) = *s;
        }
        s++;
    }
    *t = '\0';
}

void real(s, t)
char s[] ,t[];
{
    while(*s != '\0') {
        if(*s == '\\'){
            switch(*(s + 1)) {
                case 'n':
                    *(t++) = '\n';
                    s++;
                    break;
                case 't':
                    *(t++) = '\t';
                    s++;
                    break;
                default:
                    *(t++) = '\\';
            }    
        } else 
            *(t++) = *s;
        s++;
    }
    *t = '\0';
}




