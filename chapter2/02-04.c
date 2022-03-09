// Write an alternate version of squeeze(s1, s2) that deletes each character in s1 that matches any character in the string s2.
// gcc -o a.o 02-04.c && ./a.o

#include <stdio.h>
#include <string.h>

/* squeeze: delete all c from s */
void squeeze(char s[], char c) {
    int r, w;
    r = w = 0;
    while (s[r] != '\0') {
        if (s[r] != c)
            s[w++] = s[r];
        ++r;
    }
    s[w] = '\0';
}

int contains_char(char s[], char c) {
    for (int i = 0; i < strlen(s); ++i)
        if (s[i] == c) return 1;
    return 0;
}

void squeeze2(char s1[], char s2[]) {
    int r, w;
    r = w = 0;
    while (s1[r] != '\0') {
        if (!contains_char(s2, s1[r]))
            s1[w++] = s1[r];
        ++r;
    }
    s1[w] = '\0';
}

int main() {
    char s[] = "hello world";
    squeeze(s, 'o');
    printf("%s\n", s);
    char s1[] = "hello world";
    char s2[] = "aeiou";
    squeeze2(s1, s2);
    printf("%s\n", s1);
}