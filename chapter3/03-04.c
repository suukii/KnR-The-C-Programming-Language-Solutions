// In a two's complement number representation, our version of itoa does not handle the largest negative number,
// that is, the value of n equal to -(2 ^ (wordsize - 1)). Explain why not. Modify it to print that value correctly,
// regardless of the machine on which it runs.
// gcc -o a.o 03-04.c && ./a.o

// Because in the context of two's complement, the negative of the largest negative number cannot be presented.
// the largest positive number is 2 ^ (wordsize - 1) - 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void reverse(char line[]);
void itoa(int n, char s[]);
void refined_itoa(int n, char s[]);

int main() {
    char s[100];
    itoa(1234567, s);
    printf("%s\n", s);
    itoa(INT_MIN, s);
    printf("%s\n", s);
    refined_itoa(INT_MIN, s);
    printf("%s\n", s);
    printf("%d\n", INT_MIN);
}

/* itoa: convert n to characters in s */
void itoa(int n, char s[]) {
    int i, sign;
    if ((sign = n) < 0)
        n = -n;

    i = 0;
    do {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0) s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

void refined_itoa(int n, char s[]) {
    int i, sign;
    i = 0;
    sign = n;
    do {
        s[i++] = abs(n % 10) + '0';
    } while (n /= 10);
    if (sign < 0) s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

void reverse(char line[]) {
    int l = 0, r = strlen(line) - 1;
    while (l < r) {
        char t = line[l];
        line[l] = line[r];
        line[r] = t;
        l++;
        r--;
    }
}