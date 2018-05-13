#include<stdio.h>


int main (void){
	int c;
	int count = 0;

	while ( (c = fgetc(stdin)) != EOF ){
		if (c == ' ' || c == '\t') {
                       if(count == 0) {
			fputc('\n', stdout);
			count++;
                   }
		}else {
			fputc(c, stdout);
			count = 0;
		}
	}
	return 0;
}



