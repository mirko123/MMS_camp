#include <stdio.h>

int binsearch(const int *array, const int N, const int v) {
	int B, E, p;
	
	for (B = 0, E = N - 1; B <= E; ) {
		p = B + (E - B)/2;
		if (array[p] == v) return p;
		else if (array[p] > v) E = p - 1;
		else B = p + 1;
	}
	
	return -1;
}

int main(void) {
	int t[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	
	printf("%d\n", binsearch(t, 10, 11));
	printf("%d\n", binsearch(t, 10, 7));
	printf("%d\n", binsearch(t, 10, 5));
	
	return 0;
}
