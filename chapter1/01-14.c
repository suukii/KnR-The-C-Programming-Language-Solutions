// Write a program to print a histogram of the frequencies of different characters in its input.
// gcc -o a.o 01-14.c && cat text.txt | ./a.o

// Hints:
// Minus 'a' to Convert a char to int.
// Add '0' to Convert an int to char.

#include <stdio.h>

#define NEWLINE '\n'
#define BLANK ' '
#define TAB '\t'
#define LETTERS 26

#define CHAR_TO_INT(c) (c - 'a')
#define INT_TO_CHAR(i) ((i + 49) + '0')

int main() {
    int freq[LETTERS];
    int c;

    for (int i = 0; i < LETTERS; ++i)
        freq[i] = 0;

    while ((c = getchar()) != EOF) {
        if (c != NEWLINE && c != BLANK && c != TAB)
            ++freq[CHAR_TO_INT(c)];
    }

    int max_count = 0;
    for (int i = 0; i < LETTERS; ++i)
        if (freq[i] > max_count) max_count = freq[i];
    
    for (int j = max_count; j >= 1; --j) {
        printf("%3d |", j);
        for (int i = 0; i < LETTERS; ++i) {
            if (freq[i] >= j) printf(" * ");
            else printf("   ");
        }
        putchar('\n');
    }

    printf("    +");
    for (int i = 0; i < LETTERS; ++i)
        printf("---");
    putchar('\n');
    printf("     ");
    for (int i = 0; i < LETTERS; ++i)
        printf(" %c ", INT_TO_CHAR(i));
    putchar('\n');
    
}