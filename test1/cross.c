#include <stdio.h>

#define N 8

int main(void) {
	int i, j;
	
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++)
			if (
				(j == i) ||
				(j == (N - i - 1)) ||
				(j == 0) ||
				(j == (N - 1)) ||
				(i == 0) ||
				(i == (N - 1))
			) fputc('#', stdout);
			else fputc('.', stdout);
		fputc('\n', stdout);
	}
	
	return 0;
}

