// Write a program to check a C program for rudimentary syntax errors like unmatched
// parentheses, brackets and braces. Don't forget about quotes, both single and
// double, escape sequences, and comments. (This program is hard if you do it in full
// generality.)

#include <stdio.h>
#include <libc.h>

char* jumpToNextLine(char* input);
char* jumpAfterStarSlash(char* input);
char* removeComments(char *input);
char* removeTextInQuotes(char *input);
int isValid(char* source);

int main(int argc, char *argv[]) {
    char *input = strdup("1 '5'// ");
    //    char *output = isValid(input);
    //    if(!output) {
    //        printf("NULL\n");
    //    }
    //    else printf("%s\n", output);
    printf("%d\n",isValid(input));
    
    return 0;
}


int isValid(char* source) {
    char *withoutComments = removeComments(source);
    char *withoutCommentsAndQuotes = removeTextInQuotes(withoutComments);
    char *navigator;
    char symbol;
    char nextBracketToClose;
    int length = strlen(withoutCommentsAndQuotes);
    int bracketsSquare = 0;
    int bracketsCircle = 0;
    int bracketsShano = 0;
    int check = 1;
    int i;
    
    check = withoutCommentsAndQuotes? 1:0;
    
    for (i = 0; i < length && check; ++i) {
        symbol = withoutCommentsAndQuotes[i];
        switch(symbol) {
            case '(':
                bracketsCircle++;
                break;
            case ')':
                bracketsCircle--;
                break;
            case '[':
                bracketsSquare++;
                break;
            case ']':
                bracketsSquare--;
                break;
            case '{':
                bracketsShano++;
                break;
            case '}':
                bracketsShano--;
                break;
        }
        if(bracketsCircle < 0 || bracketsSquare < 0 || bracketsShano < 0) {
            check = 0;
            break;
        }
    }
    
    
    if(bracketsCircle > 0 || bracketsSquare > 0 || bracketsShano > 0) {
        check = 0;
    }
    
    return check;
}

char* removeTextInQuotes(char *input) {
    char *output;
    char *navigator;
    char symbol;
    int inputLength = strlen(input);
    int check = 1;
    int i = 0;
    output = (char*)malloc(inputLength*sizeof(char));
    
    
    for (navigator = input, i = 0; *navigator; navigator++, i ++){
        symbol = *navigator;
        if(symbol == '\'' || symbol == '\"') {
            navigator++;
            while(*navigator && *navigator != symbol) {
                navigator++;
            }
            
            if(!(*navigator)) {
                check = 0;
                break;
            }
            navigator++;
        }
        
        output[i] = *navigator;
    }
    output[i] = '\0';
    // printf("%s\n", output);
    
    if(!check) {
        return NULL;
    }
    
    return output;
}


char* removeComments(char *input) {
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
    // printf("%s\n", output);
    
    return output;
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



