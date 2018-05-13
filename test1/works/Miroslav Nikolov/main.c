#include <stdio.h> 
#include <stdlib.h>

//#include "p1.h"
#include "p2.h"
#include "p3.h"

//void test1(void);
//void test2(void);
void test3(void);

int main(void) {
	//test1();
	test3();
	//test();	
	return 0;
}


void test3(void) {
	int rows = 6;
	int cols = 6;
	int size = rows*cols;
	unsigned char* arr = (unsigned char*)malloc(size*(sizeof(char)));
	clear(arr,size);
	int row = 1;
	int col = 5;
	
	int val;

	val = getpix(arr, rows, cols, row, col);
	printf("%i \n", val);
	setpix(arr,rows,cols,row,col,1);
	set(arr,(rows*cols),9, 1);

	val = getpix(arr, rows, cols, row, col);
	printf("%i \n", val);
	set(arr,(rows*cols),9, 1);
	printf("%i \n", get(arr, rows*cols, 9));

	display(arr,rows,cols);
}


void test2(void) {
	int size = 25;
	unsigned char* arr = (unsigned char*)malloc(size*(sizeof(char)));
	int bit = 5;
	int val;

	set(arr,size,bit,1);
	val = get(arr,size,bit);
	printf("%d \n", val);

	//clear(arr,size);
	set(arr,size,bit,0);

	//display(arr,5,5);

	val = get(arr,size,bit);
	printf("%i \n", val);
}
/*
void test1(void) {
	int size = 64;
	unsigned int* arr = (unsigned int*)malloc(size/(sizeof(int)));
	int bit = 35;
	int val;

	set(arr,size,bit,1);
	val = get(arr,size,bit);
	printf("%i \n", val);

	clear(arr,size);

	val = get(arr,size,bit);
	printf("%i \n", val);
}*/








