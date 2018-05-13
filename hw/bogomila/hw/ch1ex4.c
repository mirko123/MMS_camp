#include <stdio.h>

/* Celsius to Fahrenheit teable */

int main(void)
{
        int lower = 0;
        int upper = 150;
        int step = 10;

	int cels;

	for(cels = lower; cels < upper; cels += step)
	{
		printf("%2d\t%0.2f\n", cels, (cels * (9.0/5.0)) + 32.0);
	}

	return 0;
}
