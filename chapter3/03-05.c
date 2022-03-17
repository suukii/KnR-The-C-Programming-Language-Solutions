// Write the function itob(n,s,b) that converts an integer into a base |b| character representation in the string |s|.
// In particular, itob(n, s, 16) formats |n| as a hexadecimal integer in |s|.
// gcc -o a.o 03-05.c && ./a.o

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void reverse(char line[]);

void itob(int n, char s[], int b) {
    if (b < 2 || b > 36) {
        fprintf(stderr, "EX3_5: Cannot support base %d\n", b);
        exit(EXIT_FAILURE);
    }

    char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int i, sign;
    sign = n;
    i = 0;
    do {
        s[i++] = digits[abs(n % b)];
    } while (n /= b);
    if (sign < 0) s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

int main() {
    char s[100];
    itob(5, s, 2);
    printf("%s\n", s);
    itob(-5, s, 2);
    printf("%s\n", s);
    itob(1000, s, 16);
    printf("%s\n", s);
    itob(1000, s, 37);
    printf("%s\n", s);
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