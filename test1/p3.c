#include <stdio.h>

#include "p2.h"
#include "p3.h"

int getpix(const unsigned char *display, int M, int N, int X, int Y) {
	if ((X < 0) || (X >= N) || (Y < 0) || (Y >=M)) return -1;
	return get(display, M * N, Y * N + X);
}

int setpix(unsigned char *display, int M, int N, int X, int Y, int colour) {
	if ((X < 0) || (X >= N) || (Y < 0) || (Y >=M)) return -1;
	return set(display, M * N, Y * N + X, colour);
}

void display(const unsigned char *display, int M, int N) {
	int i, j;
	
	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++)
			printf("%c", getpix(display, M, N, j, i) ? '#' : '.');
		fputc('\n', stdout);
	}
	
	return;
}

