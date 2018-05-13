#include <stdio.h>
#include <libc.h>
#include <math.h>
float getFloat(char* str);

int main(int argc, char* argv[]) {
	
	float val = getFloat(strdup("12.123335"));
	printf("%f\n", val);
	return 0;
}

float getFloat(char* str) {
	float result; 
	int direction = 1;
	int digitAfterPoint;

	switch(*str) {
		case '0': 
			result = 0;
			break;
		case '-': 
			direction = -1;
			break;
		case '+': 
			direction = 1;
			break;
		default:
			str--;
			break;
	}
	result=(str[1] - '0');
	str+=2;

	while(*str != '\0' && '0' <= *str && *str <= '9') {
		result*=10;
		result+=(*str - '0');
		str++;
	}
	if(*str == '.') {
		str++;
	}

	digitAfterPoint = 0;
	while(*str != '\0' && '0' <= *str && *str <= '9') {
		result*=10;
		result+=(*str - '0');
		str++;
		digitAfterPoint++;
	}

	result *= pow(10,-digitAfterPoint);
	return result;
}





