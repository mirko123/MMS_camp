#include <stdio.h>

int main(void){
	int c;
	int i;

	i = 0;
	while((c = getchar()) != '\n')
	{
		if (c == EOF) break;
		
		printf("%d \n", c);
	}
	
}
