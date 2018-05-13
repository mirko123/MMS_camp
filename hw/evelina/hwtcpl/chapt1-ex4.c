#include <stdio.h>

int main(void)
{
    int cl;
	double fr;
	int lower,step,upper;
	// cl=5/9*(fr-32) => fr= 9/5 * cl +32
	lower=0;
	step=20;
	upper=300;
	
	printf("Celsius: \t Fahrenheit: \n");
	
	cl=lower;
	while(cl<=upper)
	{
		fr= cl*9/5 +32;
		printf("%d \t \t %f \n", cl, fr);
		cl+=step;
	}
	
	return 0;
}