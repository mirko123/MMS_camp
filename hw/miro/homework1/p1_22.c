// Write a program to ``fold'' long input lines into two or more shorter lines
// after the last non-blank character that occurs before the n-th column of input.
// Make sure your program does something intelligent with very long lines, and if
// there are no blanks or tabs before the specified column.

#include <stdio.h>
#include <libc.h>

int findSymbolIndexPreviousIndexDifferentOfSpace(char *str, int n) {
    int index = n;
    while(str[index] == ' ') {
        index--;
    }
    return index;
}

int main(int argc, char *argv[]) {
    char *str = strdup("das   asd asd asd   	 dsa 	 a 			d a 		");
    char **lines;
    int n = 10;
    int len = strlen(str);
    int startLine;
    int endLine;
    int lineSize;
    int i;
    int line;
    
    // printf("n: ");
    // scanf("%d",&n);
    
    lines = malloc(len*sizeof(char*)/n + 1);
    
    for (startLine = 0, line = 0; startLine < (len - n); startLine+=n, line++) {
        lineSize = findSymbolIndexPreviousIndexDifferentOfSpace(str + startLine, n);
        lines[line] = malloc(lineSize*sizeof(char) + 1);
        memcpy(lines[line], str + startLine, lineSize*sizeof(char));
        *(lines[line] + lineSize) = '\0';
    }
    
    for(i = 0; i < len/n && lines[i]; i++) {
        printf("%s\n", lines[i]);
    }
    
    return 0;
}










