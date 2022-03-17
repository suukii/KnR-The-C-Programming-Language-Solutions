// Write a version of |itoa| that accepts three arguments instead of two.
// The third argument is a minimum field width;
// the converted number must be padded with blanks on the left if necessary to make it wide enough.
// gcc -o a.o 03-06.c && ./a.o

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void reverse(char line[]);
void itoa(int n, char s[], int w);

int main() {
    char s[100];
    itoa(1234567, s, 10);
    printf("%s\n", s);
    itoa(INT_MIN, s, 20);
    printf("%s\n", s);
}

void itoa(int n, char s[], int w) {
    int i, sign;
    i = 0;
    sign = n;
    do {
        s[i++] = abs(n % 10) + '0';
    } while (n /= 10);
    if (sign < 0) s[i++] = '-';
    while (i < w) s[i++] = ' ';
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