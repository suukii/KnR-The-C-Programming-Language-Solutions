// Write a program to remove trailing blanks and tabs from each line of input, and to delete entirely empty line.
// gcc -o a.o 01-18.c && cat text.txt | ./a.o

#include <stdio.h>

#define NEWLINE '\n'
#define TAB '\t'
#define BLANK ' '
#define MAXLEN 1000

int getLine(char line[], int lim);

int main() {
    int len = 0;
    char line[MAXLEN];
    while ((len = getLine(line, MAXLEN))) {
        int head = 0, tail = len - 2;
        while (tail >= 0 && (line[tail] == BLANK || line[tail] == TAB))
            --tail;
        while (head <= tail)
            putchar(line[head++]);
        if (tail >= 0) {
            putchar('|'); /* To make the elimination of trailing blanks visible. */
            putchar('\n');
        }
    }
}

int getLine(char line[], int lim) {
    char c;
    int i = 0;
    while ((c = getchar()) != NEWLINE && c != EOF && i < lim) {
        line[i++] = c;
    }
    if (c == NEWLINE) line[i++] = c;
    line[i] = '\0';
    return i;
}