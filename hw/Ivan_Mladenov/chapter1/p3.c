#include <stdio.h>

int main(void) {

	float fahr, celsius;
	float lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	celsius = lower;

	printf("Temperature conversion table \n");

	while (celsius <= upper) {
		fahr = (celsius * 9 / 5) + 32;
		printf("%3.0f %6.1f \n",celsius, fahr);
		celsius += step;
	}

	printf("reverce table\n");

	celsius = upper;
	while (celsius >= lower) {
		fahr = (celsius * 9 / 5) + 32;
		printf("%3.0f %6.1f \n",celsius, fahr);
		celsius -= step;
	}


return 0;
}
