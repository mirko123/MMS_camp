#include <stdio.h>

int main()
{
	int fr,cl;
	int lower, upper, step;
	
	lower=0;
	upper=300;
	step=20;
	
	printf("Fahrenheit:  Celsius: \n");
		fr=lower;
		while (fr<= upper)
		{
			cl=5*(fr-32)/9;
			printf("%d \t \t %d \n", fr, cl);
			fr+=step;
		}

	return 0;
}