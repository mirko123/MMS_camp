#include <stdio.h>
#include <libc.h>
#include <math.h>

int getInt(char* str);

int main(int argc, char* argv[]) {
	
	int val = getInt(strdup("123"));
	printf("%d\n", val);
	return 0;
}

int getInt(char* str) {
	int result = 1;
	int direction = 1;

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
	result*=direction;
	return result;
}

