// Expand |atof| to handle scientific notation of the form "123.45e-6", 
// where a floating-point number may be followed by e or E and an optionally signed exponent.
// gcc -o a.o 04-02.c && ./a.o

#include <stdio.h>
#include <ctype.h>
#include <math.h>

double atof(char s[]);
double expanded_atof(char s[]);

int main() {
    char a[] = "123.45";
    char b[] = "-123.45";
    char c[] = "+123.45";
    char d[] = "   123";
    char e[] = "123.45e-6";
    char f[] = "12.45e3";
    printf("%g\n", atof(a));
    printf("%g\n", atof(b));
    printf("%g\n", atof(c));
    printf("%g\n", atof(d));
    printf("%g\n", expanded_atof(e));
    printf("%g\n", expanded_atof(f));
}

double atof(char s[]) {
    double res, power;
    int i, fraction, sign;

    res = 0.0;
    power = 1.0;
    i = fraction = 0;

    while (s[i] == ' ') ++i; // skip leading spaces

    sign = s[i] == '-' ? -1 : 1;

    while (s[i] != '\0') {
        if (isdigit(s[i])) {
            res = res * 10.0 + (s[i++] - '0');
            if (fraction) power *= 10.0;
        } else if (s[i] == '.') {
            fraction = 1;
            ++i;
        } else if (s[i] == '+' || s[i] == '-') {
            ++i;
        } else break;
    }
    return sign * res / power;
}

double expanded_atof(char s[]) {
    double res, power, exp, sign;
    int i;

    res = atof(s);
    power = 1.0;
    exp = 0.0;
    i = 0;
    sign = 1;

    while (s[i] != 'e' && s[i] != 'E') ++i;

    if (s[i] == 'e' || s[i] == 'E') {
        ++i;
        sign = s[i] == '-' ? -1 : 1;
        while (s[i] != '\0') {
            if (isdigit(s[i])) {
                exp = exp * 10.0 + (s[i++] - '0');
            } else if (s[i] == '+' || s[i] == '-') ++i;
            else break;
        }
        exp = pow(10.0, exp);
        power = sign < 0 ? power * exp : power / exp;
    }

    return res / power;
}