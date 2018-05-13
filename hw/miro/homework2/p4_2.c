#include <stdio.h>
#include <libc.h>
#include <string.h>
#include <math.h>

int strindex(const char *str,const char termn);
float Atof(const char *textNum) {
    int prefix = atoi(textNum);
    int center = atoi(textNum + strindex(textNum, '.') + 1);
    int degreePosition =
    strindex(textNum, 'E') != -1 ? strindex(textNum, 'E'): strindex(textNum, 'e');
    degreePosition++;
    
    int degree = atoi(textNum + degreePosition);
    int centerLength = degreePosition - strindex(textNum, '.') - 2;
    float num = (prefix + center*pow(10,-centerLength))*pow(10,degree);
    return num;
}

int main(int argc, char* argv[]) {
    char *textNum = strdup("123.45e-6");
    char *textNum2 = strdup("123.45E-6");
    float num = Atof(textNum);
    printf("%f\n",num);
    num = Atof(textNum2);
    printf("%f\n",num);
    
    return 0;
}

int strindex(const char *str,const char termn) {
    int index = 0;
    int length = strlen(str);
    for (index = 0; index < length; ++index)
    {
        if(str[index] == termn) {
            return index;
        }
    }
    return -1;
}









