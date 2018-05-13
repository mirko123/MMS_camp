// Adapt the ideas of printd to write a recursive 
// version of itoa; that is, convert an integer 
// into a string by calling a recursive routine. 

#include <stdio.h>
#include <libc.h>
#include <math.h>

void Itoa(int val, char *navigator, char* buffer);
void reverse(char *str);

int main(int argc, char* argv[]) {
	int buffSize = 20;
	char *buff;

	buff = (char*)malloc(buffSize*sizeof(char));
	Itoa(1230,buff,buff);
	printf("%s\n", buff);

	return 0;
}

void Itoa(int val, char *navigator, char* buffer) {
	int dec = val%10;
	*navigator = dec + '0';
	if(val < 10) {
		navigator[1] = '\0';
		reverse(buffer);
		return;
	}
	Itoa(val/10,navigator+1, buffer);
}

void reverse(char *str) {
	int length = strlen(str);
	char temp;
	int i;
	for (i = 0; i < length/2; ++i) {
		temp = str[i];
		str[i] = str[length - i - 1];
		str[length - i - 1] = temp;
	}
}






