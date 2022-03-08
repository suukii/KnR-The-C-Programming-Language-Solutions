// Write a program to print a histogram of the lengths of words in its input. (horizontal & vertical)
// gcc -o a.o 01-13.c && cat text.txt | ./a.o

#include <stdio.h>

#define IN 1  /* inside a word */
#define OUT 0 /* outside a word */

#define NEWLINE '\n'
#define BLANK ' '
#define TAB '\t'

#define MAX_WORD_COUNT 10

int main() {
    int state, c, cc, cur_word;
    state = c = cc = cur_word = 0;

    int word_lens[MAX_WORD_COUNT];
    for (int i = 0; i < MAX_WORD_COUNT; ++i)
        word_lens[i] = 0;

    // Count the lengths of words.
    while ((c = getchar()) != EOF && cur_word < MAX_WORD_COUNT) {
        if (c == BLANK || c == TAB || c == NEWLINE) {
            if (state == IN) {
                word_lens[cur_word++] = cc;
                cc = 0;
                state = OUT;
            }
        } else {
            ++cc;
            if (state == OUT)
                state = IN;
        }
    }
    // Print horizontally.
    for (int i = 0; i < MAX_WORD_COUNT; ++i) {
        printf("%2d| ", i + 1);
        for (int j = 0; j < word_lens[i]; ++j)
            putchar('*');
        putchar('\n');
    }

    putchar('\n');

    // Print vertically.
    int max_len = 0;
    for (int i = 0; i < MAX_WORD_COUNT; ++i)
      if (word_lens[i] > max_len) max_len = word_lens[i];

    for (int j = max_len; j >= 1; --j) {
        printf("%3d |", j);

        for (int i = 0; i < MAX_WORD_COUNT; ++i) {
            if (word_lens[i] >= j) printf(" * ");
            else printf("   ");
        }
        putchar('\n');
    }

    printf("    +");
    for (int i = 0; i < MAX_WORD_COUNT; ++i)
        printf("---");
    putchar('\n');
    printf("     ");
    for (int i = 0; i < MAX_WORD_COUNT; ++i)
        printf("%2d ", word_lens[i]);
    putchar('\n');


}