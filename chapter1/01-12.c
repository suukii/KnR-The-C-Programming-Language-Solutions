// Write a program that prints its input one word per line.
// gcc -o a.o 01-12.c && cat text.txt | ./a.o

#include <stdio.h>

#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */

#define NEWLINE '\n'
#define BLANK ' '
#define TAB '\t'

int main() {
    int state;
    int c;
    while ((c = getchar()) != EOF) {
        if (c == BLANK || c == TAB || c == NEWLINE) {
            state = OUT;
        } else {
            if (state == OUT) {
                putchar('\n');
                putchar(c);
                state = IN;
            } else {
                putchar(c);
            }
        }
    }
}