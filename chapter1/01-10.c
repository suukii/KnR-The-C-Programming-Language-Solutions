// Exercise 1-10. Write a program to copy its input to its output, 
// replacing each tab by \t, each backspace by \b, and each backslashe by \\.
// This make tabs and backspces visible in an unambiguous way.
// gcc -o a.o 01-10.c && cat text.txt | ./a.o

#include <stdio.h>

#define TAB '\t'
#define BACKSPACE '\b'
#define BACKSLASH '\\'

int main() {
    int c;
    while ((c = getchar()) != EOF) {
        if (c == TAB) {
            putchar('\\');
            putchar('t');
        }
        else if (c == BACKSPACE) {
            putchar('\\');
            putchar('b');
        }
        else if (c == BACKSLASH) {
            putchar('\\');
            putchar('\\');
        }
        else putchar(c);
    }
}