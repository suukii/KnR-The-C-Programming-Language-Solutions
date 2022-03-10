// Write the function any(s1, s2), which returns the first location in the string s1 where any character from 
// the string s2 occurs, or -1 if s1 contains no characters from s2.
// (The standard library function strpbrk does the same job but returns a pointer to the location.)
// gcc -o a.o 02-05.c && ./a.o

#include <stdio.h>
#include <string.h>

int contains_char(char s[], char c) {
    for (int i = 0; i < strlen(s); ++i)
        if (s[i] == c) return 1;
    return 0;
}

int any(char s1[], char s2[]) {
    for (int i = 0; s1[i] != '\0'; ++i) {
        if (contains_char(s2, s1[i])) return i;
    }
    return -1;
}

int main() {
    char* tests[3][2] = {
        {"hello world", "aeiou"},
        {"abcdefg", "hijklmn"},
        {"bbbbbbu", "aaaauaa"}
    };
    size_t n = sizeof(tests) / sizeof(tests[0]);
    for (int i = 0; i < n; ++i) {
        char* found = strpbrk(tests[i][0], tests[i][1]);
        int expected = found ? (int)(found - tests[i][0]) : -1;
        int got = any(tests[i][0], tests[i][1]);
        printf("expected: %d, got: %d\n", expected, got);
    }
}