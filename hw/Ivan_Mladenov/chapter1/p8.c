#include <stdio.h>

int main(void) {

	int c;
	int s, t, n, total;

	s = 0;
	t = 0;
	n = 0;
	total = 0;

	while ((c = getchar()) != EOF){
		
		if (c == ' ') ++s, ++total;
		else if (c == '\t') ++t, ++total;
		else if (c == '\n') ++n, ++total;
		else continue;
	}

	printf("Number of spaces is: %d, number of tabs is: %d, number of new lines is: %d, total number is: %d \n", s,t,n,total);

return 0;
}
