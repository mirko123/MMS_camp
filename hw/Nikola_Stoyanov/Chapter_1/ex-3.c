#include <stdio.h>
#include <stdlib.h>
	
	

	
	
int main(void) 
{
	/* Exercise 1-3. Modify the temperature conversion program to print a heading above the table. */
	int lower, upper, step;
	float fahr, celsius;
	
	lower = 0;
	upper = 300;
	step = 20;
	
	printf("\n\n");
	printf("    Fahr | Celsius\n");
	while (fahr <= upper) {
		celsius = (5.0/9.0) * (fahr - 32.0);
		printf("   %4.0f  | %6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
	return 1;
}
	

