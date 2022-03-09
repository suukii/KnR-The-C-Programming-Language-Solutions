// Write the function htoi(s), which converts a string of hexadecimal digits(including an options 0x or 0X) into its
// equivalent integer value. The allowable digits are 0 through 9, a through f, and A through F.
// gcc -o a.o 02-03.c && ./a.o

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define HEX_BASE 16
#define DEC_BASE 10

int hexalpha_to_int(char c) {
    if (isdigit(c)) return c - '0';
    if (isalpha(c)) return tolower(c) - 'a' + DEC_BASE;
    return -1;
}

int htoi(char s[]) {
    int i, n;
    i = n = 0;

    if (s[i] == '0') {
        ++i;
        if (tolower(s[i]) == 'x') ++i;
    }

    while (s[i] != '\0') {
        int d = hexalpha_to_int(s[i]);
        if (d < 0 || d >= HEX_BASE) {
            return n;
        }
        n *= HEX_BASE;
        n += d;
        ++i;
    }
    return n;
}

int main() {
    char* tests[] = {
      "F00",
      "bar",
      "0100",
      "0x1",
      "0XA",
      "0X0C0BE",
      "abcdef",
      "123456",
      "0x123456",
      "deadbeef",
      "zog_c",
      "12f",
      "abf"
    };
    size_t tests_number = sizeof(tests) / sizeof(tests[0]);
    for (int i = 0; i < tests_number; ++i) {
        int expected = (int)strtoul(tests[i], NULL, HEX_BASE);
        int got = htoi(tests[i]);
        printf("%s expected: %-11d got: %d\n", expected == got ? "✅" : "❌", expected, got);
    }
}