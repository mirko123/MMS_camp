#include <stdio.h>
#include <libc.h>
#include <math.h>

int main(int argc, char* argv[]) {
	float sin_ = sin(45);
	float exp_ = exp(10);
	float pow_ = pow(2,10);

	printf("%f\n", sin_);
	printf("%f\n", exp_);
	printf("%f\n", pow_);
	return 0;
}

