#include "p2.h"

void clear(unsigned char *arr, int N) {
	//(*arr)&=(~(1<<N));
	int i;
	//int count = sizeof(int)/N;
	//for(i = 0; i < count; i++) {
	//	(*arr)&=0;
	//}
	for(i = 0; i < N; i++) {
		set(arr,N,i,0);	
	}
}
int get(const unsigned char *arr, int N, int bit) {
	if(bit < 0 || N <= bit) return -1;
	const char *p = arr + (N/sizeof(char));
	int value = !!((*p)&(1<<bit));
	return value;
}
int set(unsigned char *arr, int N, int bit, int boolean) {
	if(bit < 0 || N <= bit) return -1;
	
	char *p = arr + (N/sizeof(char));
	if(boolean == 0) {
		(*p) &= ~(1<<bit);
	}
	else if(boolean == 1){
		(*p) |= (1<<bit);
	} 
	else {
		return -1;
	} 
	return 1;
}

