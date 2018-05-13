#include <stdio.h>
#include <stdlib.h>
	
int celsius_to_fahrenheit(int lower, int upper, int step);

int main(void) 
{
	/* Exercise 1-4. Write a program to print the corresponding Celsius to Fahrenheit table. */
	/* Exercise 1-5. Modify the temperature conversion program to print the table in reverse order, that is, from 300 degrees to 0.*/
	celsius_to_fahrenheit(0, 300, 20);
	
	return 1;
}

int celsius_to_fahrenheit(int lower, int upper, int step)
{
	float fahr, celsius;

	celsius = upper;
	
	printf("\n\n");
	printf(" Celsius |   Fahr\n");
	while (celsius >= lower) {
		fahr = celsius * (9.0/5.0) + 32;
		printf("   %4.0f  | %6.1f\n", celsius, fahr);
		celsius = celsius - step;
	}	
}
