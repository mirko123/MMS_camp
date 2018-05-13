#include <stdio.h>
/* 
Rewrite the temperature conversion program of Section 1.2 to use a function for
conversion.
*/
double cels(double fr)
{
	return (5.0/9.0)*(fr-32.0);
};

int main()
{
	double fr;
	int lower, upper, step;
	
	lower = 0;    
	upper = 300; 
	step = 20; 
	
	fr = lower;
	while (fr <= upper) {
		printf("%3.0f %6.1f\n", fr, cels(fr));
		fr += step;
	}

	return 0;
}


