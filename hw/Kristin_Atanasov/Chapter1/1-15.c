#include <stdio.h>

void convert(int *p, int y);

int main(void){
    int fahr;
    int lower, upper, step;
    lower = 0; /* lower limit of temperature scale */
    upper = 300; /* upper limit */
    step = 20; /* step size */
    fahr = lower;

    while (fahr <= upper) {

        convert(&fahr, step);
 /*       celsius = 5 * (fahr-32) / 9;
        printf("%d\t%d\n", fahr, celsius);
        fahr = fahr + step; */
    }
    return 0;
}

void convert(int *p, int y){
    int *x = p;
    printf("%d\t%d\n", *x, (5 * (*x - 32) / 9));
    *x+=y;
}
