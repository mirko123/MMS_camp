#include "p1.h"

int main(void){

int N;
unsigned int arr [5] = {'1', '0', '1', '0', '1'};
N = sizeof(arr)/sizeof(arr[0]);

return 0;
}

void clear(unsigned int *a, int N){

for (int i = 0; i < N; i ++)
	a &= ~(1<<i);
	
return a;
}

int get(const unsigned int *a, int N, int bit){

for (int i = 0; i < N; i ++)
	if ((i == bit) && (a & (1<<bit)) == 0)) {
		return 0;
	} else if ((i == bit) && (a & (1<<bit)) == 1)) {
		return 1;
	}
return NULL;	
}

int set(unsigned int *a, int N, int bit, int boolean) {

for (int i = 0; i < N; i ++) {
	if (i == bit){
		return (int) a |= (boolean<<bit);
	}
		return NULL;	
}
}
