#include <stdio.h>
#include <stdlib.h> 

#include "p4.h"
#include "p3.h"
#include "p2.h"

void test(void) {
	int rows = 8;
	int cols = 8;
	int row, col;
	int size = rows*cols;
	unsigned char* arr = (unsigned char*)malloc(size/(sizeof(char)));
	clear(arr, size);

	for(row = 0; row < rows; row++) {
		for(col = 0; col < cols; col++) {
			if(row == 0 || row == (rows - 1) || 
				col == 0 || col == (cols - 1) || 
				row == col || col == (rows - row - 1))
			{
				setpix(arr, rows, cols, row, col, 1);
			}	
		}	
	}
	display(arr, rows, cols);
}

