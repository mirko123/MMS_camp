#include <stdio.h>
#define IN 1
#define OUT 0

int main(void) {
	int wordlength[50];
	int i,j, c, length, state, max;

	i = j = c = length = max = 0;
	state = OUT;

	for (i = 0; i < 50; ++i)
		wordlength[i] = 0;

	while((c = getchar()) != EOF){
		if(c == '\n' || c == '\t' || c == ' '){
			state = OUT;
			if( length > 0 && length < 50 ){
				if (length > max)
					max = length;
				wordlength[length]++;
			}
			length = 0;
		}
		else{
			state = IN;
			length++;
		}
	}
	printf("Histogram\n");
	for(i = 0; i < max; ++i)
		printf("___");
	printf("\n");
	for(i = max; i > 0; --i){
		printf("%2d", i);
		for(j = 0; j <= max; ++j){
			if(wordlength[j] >= i)
				printf("|%2s","");
			else{
				printf("%3s","");
			}
		}
		printf("\n");
	}
	for(i =0; i <= max; ++i){
		if(i <= 10){
			printf("%2s%d","",i);
		}
		else{
			printf("%3d",i);
		}
	}
	printf("\n");
	for(i = 0; i < max; ++i)
		printf("___");
	printf("\n");

    return 0;
}
