#include <stdio.h>
#include <stdlib.h>
	
	
int fahrenheit_to_celsius(int lower, int upper, int step);
	
	
int main(void) 
{
	//Exercise 1.15. Rewrite the temperature conversion program of Section 1.2 to use a function for conversion.
	fahrenheit_to_celsius(0, 300, 20);
	
	return 1;
}
	
int fahrenheit_to_celsius(int lower, int upper, int step)
{
	float fahr, celsius;
	
	fahr = lower;
	
	printf("\n\n");
	printf("    Fahr | Celsius\n");
	while (fahr <= upper) {
		celsius = (5.0/9.0) * (fahr - 32.0);
		printf("   %4.0f  | %6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}	
}
