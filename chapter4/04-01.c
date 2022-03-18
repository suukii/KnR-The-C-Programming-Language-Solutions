// Write the function strrindex(s, t), which returns the position of the rightmost occurence of |t| in |s|,
// or -1 if there is none.
// gcc -o a.o 04-01.c && ./a.o

#include <stdio.h>

int strrindex(char s[], char t);

int main() {
    char s[] = "hello world";
    printf("The position of the rightmost ocurrence of %c is %d\n", 'o', strrindex(s, 'o'));
    printf("The position of the rightmost ocurrence of %c is %d\n", 'l', strrindex(s, 'l'));
    printf("The position of the rightmost ocurrence of %c is %d\n", 'a', strrindex(s, 'a'));
}

int strrindex(char s[], char t) {
    int i, index;
    i = 0;
    index = -1;
    while (s[i] != '\0') {
        if (s[i] == t) index = i;
        ++i;
    }
    return index;
}