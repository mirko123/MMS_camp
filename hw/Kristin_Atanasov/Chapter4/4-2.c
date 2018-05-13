#include <stdio.h>
#include <ctype.h>
#define MAXLINE 100
int getline(char s[], int lim);
double atof(char s[]);

int main(void) {
    double sum, atof(char []);
    char line[MAXLINE];
    int getline(char line[], int max);
    sum = 0;

    while (getline(line, MAXLINE) > 0)
        printf("\t%.10f\n", sum += atof(line));
    return 0;
}
int getline(char s[], int lim) {
    int c, i;
    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}
double atof(char s[]) {
    double val, power, exponent, sum;
    int i, sign;
    int esign = 1;


    for (i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }
    if (s[i] == 'e' || s[i] == 'E') {
        i++;
        esign = (s[i] == '-') ? -1 : 1;
        if ((s[i] == '+' || s[i] == '-')) {
            i++;
        }
        for (exponent = 0.0; isdigit(s[i]); i++) {
            exponent = 10.0 * exponent + (s[i] - '0');
        }
        exponent = exponent * esign;
        if (exponent > 0)
            while (exponent-- > 0)
                val = val * 10;
        else if (exponent < 0)
            while (exponent++ < 0)
                val = val / 10;
    }
    return sign * val / power;
}
