#include <stdio.h>
#include <libc.h>
#include <string.h>

int module(int num, int devisor);

int main(int argc, char* argv[]) {
	int index = module(23,3);
	printf("%d\n", index);
	return 0;
}

int module(int num, int devisor) {
	int counter = num / devisor;
	int result = num - devisor*counter;
	result = abs(result);
	return result;
}
