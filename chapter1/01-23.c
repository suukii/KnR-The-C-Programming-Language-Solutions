// Write a program to remove all comments from a C program.
// Don't forget to handle quoted strings and character constants properly.
// C comment do not nest.
// gcc -o a.o 01-23.c && cat 01-23.c | ./a.o

#include <stdio.h>
#include <string.h>

#define NEWLINE '\n'
#define CODE 1
#define SINGLE_COMMENT 2
#define BLOCK_COMMENT 3
#define QUOTE 4

int main() {
    char someTestString[] = "some test string with // and /**/";
    /* Some
        block
        comments
    */
    /** Some
        block
        // comments
    **/

    int state = CODE;
    int seenSlash = 0;
    int seenStar = 0;

    int c;
    while ((c = getchar()) != EOF) {
        switch (state) {
            case QUOTE:
                putchar(c);
                if (c == '"') state = CODE;
                break;
            case SINGLE_COMMENT:
                if (c == NEWLINE) state = CODE;
                break;
            case BLOCK_COMMENT:
                if (c == '*') seenStar = 1;
                else if (c == '/' && seenStar) {
                    state = CODE;
                    seenStar = 0;
                } else seenStar = 0;
                break;
            case CODE:
                if (c == '"') {
                    putchar(c);
                    state = QUOTE;
                } else if (seenSlash) {
                    if (c == '/') state = SINGLE_COMMENT;
                    else if (c == '*') state = BLOCK_COMMENT;
                    else {
                        putchar('/');
                        putchar(c);
                    }
                    seenSlash = 0;
                } else {
                    if (c == '/') seenSlash = 1;
                    else putchar(c);
                }
                break;

            default:
                break;
        }
    }
}