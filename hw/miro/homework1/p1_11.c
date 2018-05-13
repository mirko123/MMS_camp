#include <stdio.h>

#define IN 1 /* inside a word */ 
#define OUT 0 /* outside a word */
/* count lines, words, and characters in input */ 

int main(void) {
	char *testWords[] = {
		"", " ","\t", "\b"," test", "test "," _ "," _ 	", "%s", "%d", "%p"
	};
	return 0;
}
