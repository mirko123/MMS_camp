#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *hex1 = "0x000000ff";
	char *hex2 = "0x0000FFff";
	unsigned int val1 = 0;
	unsigned int val2 = 0;
	
	//Exercise 2-3. Write a function htoi(s), which converts a string of
	// hexadecimal digits (including an optional 0x or 0X) into its 
	//equivalent integer value. The allowable digits are 0 through 9, a through f, and A through F.
	val1 = htoi(hex1);
	val2 = htoi(hex2);
	printf("Hexadecimal1 = %s Hexadecimal2 = %s\n", hex1, hex2);
	printf("Integer1 = %d Integer2 = %d\n", val1, val2);
	return 0;
}


int htoi(char *hex) 
{
	int integer_value;
	for (; *hex != '\0'; hex++) {
        integer_value *= 16;
        if (*hex >= '0' && *hex <= '9') {
            integer_value += *hex - '0';
        } else if (*hex >= 'a' && *hex <= 'f') {
            integer_value += 10 + (*hex - 'a');
        } else if (*hex >= 'A' && *hex <= 'F') {
            integer_value += 10 + (*hex - 'A');
        } 
	}
	return integer_value;
}

