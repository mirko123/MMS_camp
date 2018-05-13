#include <stdio.h> 

#include "p3.h"
#include "p2.h"

int getpix(const unsigned char* arr, int rows, int cols, int row, int col) {
	if(row < 0 || col < 0 || rows <= row || cols <= col) return -1;
	
	int index = (row*cols) + col;
	//printf("index %d    size %d    val %d \n", index,(rows*cols), get(arr, (rows*cols), index));
	return get(arr, (rows*cols), index);
}

int setpix(unsigned char* arr, int rows, int cols, int row, int col, int colour) {
	if(row < 0 || col < 0 || rows <= row || cols <= col) return -1;
	
	int index = (row*cols) + col;
	int res = set(arr, (rows*cols), index, colour);
	//printf("_______index %d    size %d    val %d    coul %d   res %d \n", index,(rows*cols), get(arr, (rows*cols), index), colour, res);
	return 1;
}

void display(const unsigned char* arr, int rows, int cols) {
	int row;
	int col;
	char symbol;
	int val;
	for(row = 0; row < rows; row++) {
		for(col = 0; col < cols; col++) {
			val = getpix(arr, rows, cols, row, col);
			//printf("%d", val);
			char symbol = (val == 1 ? '#':'.');
			printf("%c", symbol);		
		}
		printf("\n");	
	}
	printf("\n");
}
