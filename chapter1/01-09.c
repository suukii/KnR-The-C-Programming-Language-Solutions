// Exercise 1-9. Write a program to copy its input to its output, 
// replacing each string of one or more blanks by a single blank.
// gcc -o a.o 01-09.c && cat text.txt | ./a.o

#include <stdio.h>

#define BLANK ' '

int main() {
    int c;
    int seen_blank = 0;
    while ((c = getchar()) != EOF) {
        if (c != BLANK) {
            putchar(c);
            seen_blank = 0;
        } else if (!seen_blank) {
            seen_blank = 1;
            putchar(c);
        }
        // do not output extra blanks
    }
}