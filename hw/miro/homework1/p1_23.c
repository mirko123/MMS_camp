// Write a program to ``fold'' long input lines into two or more shorter lines
// after the last non-blank character that occurs before the n-th column of input.
// Make sure your program does something intelligent with very long lines, and if
// there are no blanks or tabs before the specified column.

#include <stdio.h>
#include <libc.h>

char* jumpToNextLine(char* input);
char* jumpAfterStarSlash(char* input);


int main(int argc, char *argv[]) {
    char *input = strdup("1// 2 3 \n4 5 6 7 /*8 9 10 */11 12 13 14 15");
    char *output;
    char *navigator;
    int inputLength = strlen(input);
    int i = 0;
    output = (char*)malloc(inputLength*sizeof(char));

    for (navigator = input, i = 0; *navigator; navigator++, i ++){
        if(*navigator == '/') {
            if(*(navigator + 1) == '/') {
                navigator = jumpToNextLine(input);
            }
            else if(*(navigator + 1) == '*') {
                navigator = jumpAfterStarSlash(input);
            }
        }
        output[i] = *navigator;
    }
    output[i] = '\0';
    printf("%s\n", output);
    
    return 0;
}


char* jumpToNextLine(char* input) {
    while(*input && *input != '\n') {
        input++;
    }
    return input;
}
char* jumpAfterStarSlash(char* input) {
    while(*input && !(*input == '*' && *(input+1) == '/' )) {
        input++;
    }
    input+=2;
    return input;
}








