#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define LEN 2000

int binary_original (int x, int v[], int n);
int binary_modified (int x, int v[], int n);

int main(void) 
{
    // Exercise 3-1. Our binary search makes two tests inside the loop, 
    // when one would suffice (at the price of more tests outside.) 
    // Write a version with only one test inside the loop and measure 
    // the difference in run-time.
    int i;
    int arr[LEN] = {0};
    int result1, result2;
    clock_t t;
    double time_taken1, time_taken2;
    
    for (i = 0; i < LEN; i++)
        arr[i] = i;
    
    
    t = clock();
    for (i = 0; i < LEN; i++)
        result1 = binary_original(i,arr,LEN);
    t = clock() - t;
    time_taken1 = ((double)t)/CLOCKS_PER_SEC;
    
    t = clock();
    for (i = 0; i < LEN; i++)
        result2 = binary_modified(i,arr,LEN);
    t = clock() - t;
    time_taken2 = ((double)t)/CLOCKS_PER_SEC;
   
    printf ("Original binary search: %d Time taken: %f\n", result1, time_taken1);
    printf("Modified binary search: %d Time taken: %f\n", result2, time_taken2);
}
int binary_original (int x, int v[], int n)
{
    int low, high, mid;
    
    low = 0;
    high = n - 1;
    
    while (low <= high) {
    	
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else /* found match */
        	return(mid);
    }
    return (-1);
}

int binary_modified (int x, int v[], int n)
{
    int low, high, mid;
    
    low = 0;
    high = n - 1;
    
    mid = high / 2;
    
    while (low < high && x != v[mid]) {
        if (x < v[mid])
            high = mid - 1;
        else
            low = mid + 1;
        mid = (low + high) / 2;
    }
    
    if (x == v[mid])
        return mid;
    return -1;
}



