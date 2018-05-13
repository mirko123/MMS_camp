
#include <stdio.h>
#include <limits.h>

int main()
{
    unsigned char uc;
    signed char c;
    unsigned short us;
    signed short s;
    unsigned int ui;
    signed int i;
    unsigned long ul;
    signed long l;
    //Exercise 2-1. Write a program to determine the ranges of char, short, int, and long variables, both signed and unsigned,
    //by printing appropriate values from standard headers and by direct computation. 
    //Harder if you compute them: determine the ranges of the various floating-point types.
    printf("  Signed    Value Range \n");
    printf("char:       %d   |   %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("short:      %d   |   %d\n", SHRT_MIN, SHRT_MAX);
    printf("int:        %d   |   %d\n", INT_MIN, INT_MAX);
    printf("long:       %ld  |   %ld\n", LONG_MIN, LONG_MAX);
    
    printf("  Unsigned    Value Range \n");
    printf("char:             %u \n", UCHAR_MAX);
    printf("short:            %u \n", USHRT_MAX);
    printf("int:              %u \n", UINT_MAX);
    printf("long:             %lu \n", ULONG_MAX);

    
   
    return 0;
}

