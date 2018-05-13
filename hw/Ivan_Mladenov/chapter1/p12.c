#include <stdio.h>

int main(void){

	int c; 
	int ws;
	ws = 0;

	while ((c = getchar()) != EOF){
		if (c == ' ' || c == '\t') {
			if (!ws) {
				ws = 1;
				putchar('\n');
			}
		} else {
			ws	 = 0;
			putchar(c);
		}	
	}

return 0;
}
