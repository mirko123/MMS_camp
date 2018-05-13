#include<stdio.h>

int main(void){
	int c;
	int tab;
	int pos = 1;

	while ((c = fgetc(stdin)) != EOF){
		if (c == '\t'){
			for(tab = 0; tab < 4; tab++)
				fputc(' ', stdout);
				pos++;
		}else if (c == '\n'){
			pos = 1;
			fputc(c, stdout);
		}else{
			fputc(c, stdout);
			pos++;
		}
	}
	return 0;
}
