// Exercise 1-8. Write a program to count blanks, tabs, and newlines.
// gcc -o a.o 01-08.c && cat text.txt | ./a.o

#include <stdio.h>

#define BLANK ' '
#define TAB '\t'
#define NEWLINE '\n'

int main() {
    int c;
    int blanks = 0, tabs = 0, newlines = 0;
    while ((c = getchar()) != EOF) {
        if (c == BLANK) ++blanks;
        if (c == TAB) ++tabs;
        if (c == NEWLINE) ++ newlines;
    }
    printf("Blanks: %d; Tabs: %d; Newlines: %d\n", blanks, tabs, newlines);
}