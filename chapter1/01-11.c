// Count lines, words, characters. (word is a sequence of characters that does not contain a blank, tab, or newline.)
// gcc -o a.o 01-11.c && cat text.txt | ./a.o

#include <stdio.h>

#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */

#define NEWLINE '\n'
#define BLANK ' '
#define TAB '\t'

int main() {
    int nl, nw, nc, c;
    nl = nw = nc = 0;
    int state;
    while ((c = getchar()) != EOF) {
        if (c == NEWLINE) ++nl;
        if (c == BLANK) ++nc;
        if (c == BLANK || c == TAB || c == NEWLINE)
            state = OUT;
        else if (state == OUT) {
            ++nw;
            state = IN;
        }
    }
    printf("line: %d, word: %d, character: %d\n", nl, nw, nc);
}