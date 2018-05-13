#include <stdio.h> 
#include <stdlib.h>

#include "p5.h"
#include "p4.h"
#include "p3.h"
#include "p2.h"

void readFile(void) {
	int rows;
	int cols;
	FILE *file = fopen("image", "r");
	fread(rows, 1, 4, file);
	fread(cols, 1, 4, file);

	int size = rows*cols;
	unsigned char* arr = (unsigned char*)malloc(size/(sizeof(char)));
	fread(arr, 1, size, file);
	display(arr, rows, cols);

	fclose(file);
}

