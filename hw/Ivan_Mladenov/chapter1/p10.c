#include <stdio.h>

int main(void){

	int c; 
	int ws;
	ws = 0;
	while ((c = getchar()) != EOF){
		if (c == '\t') printf("%s", "\\t");
		else if (c == '\b') printf("%s", "\\b");
		else if (c == '\\') printf("%s", "\\\\");
		else putchar(c);
	}

return 0;
}
