#include <stdio.h>


int convert_cel(float celsius){ 
	float fahr;

	fahr = (celsius * 9 / 5) + 32;
	
	return fahr;
}

int main(void) {

	float fahr, celsius;
	float lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	celsius = lower;

	printf("Temperature conversion table \n");

	while (celsius <= upper) {
		fahr = convert_cel(celsius);
		printf("%3.0f %6.1f \n",celsius, fahr);
		celsius += step;
	}

return 0;
}
