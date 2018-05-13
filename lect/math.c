#include <stdio.h>
#include <math.h>

int main(void) {
	double phi;
	
	for (phi = 0.0; phi < 2 * M_PI; phi += 0.001)
		printf("%lf %lf\n", sin(phi), cos(phi));
	
	return 0;
}
