// Write a function expand(s1,s2) that expands shorthand notations like a-z 
// into complete lists like abc...xyz in s2. Allow for letters of either case and digits,
// and be prepared to handle cases like a-b-c and a-z0-9 and -a-z.
// Arrange that a leading or trailing - is taken literally.
// gcc -o a.o 03-03.c && ./a.o

#include <stdio.h>
#include <ctype.h>

void expand(char s1[], char s2[]) {
    int r, w;
    r = w = 0;

    while (s1[r] != '\0') {
        if (s1[r] != '-') {
            s2[w++] = s1[r++];
            continue;
        }

        // leading or trailing -
        if (r == 0 || s1[r + 1] == '\0') {
            s2[w++] = s1[r++];
            continue;
        }

        // expanding
        char begin = s2[w - 1];
        char end = s1[r + 1];
        char offset = isdigit(begin) ? '0' : 'a';
        for (int i = begin - offset + 1; i < end - offset; ++i)
            s2[w++] = i + offset;

        ++r;
    }
    s2[w] = '\0';
}

int main() {
    char expanded[100];
    expand("-a-zA-Z0-9a-b-c-", expanded);
    printf("%s\n", expanded); // expected -abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abc-
}