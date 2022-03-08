// Write a program |detab| that replaces tabs in the input with the proper number of blanks to space to the next tab stop.
// Assume a fixed set of tab stops, say every |n| columns. Should |n| be a variable or a symbolic parameter?
// gcc -o a.o 01-20.c && cat text.txt | ./a.o

#include <stdio.h>
#include <string.h>

#define NEWLINE '\n'
#define TAB '\t'
#define BLANK ' '
#define TAB_SIZE 5
#define MAXLEN 1000

int getLine(char line[], int lim);
void detab(char to[], char from[]);

int main() {
    char line[MAXLEN], detabLine[MAXLEN];
    while (getLine(line, MAXLEN)) {
        detab(detabLine, line);
        for (int i = 0; i < strlen(detabLine); ++i)
            putchar(detabLine[i]);
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

void detab(char to[], char from[]) {
    int i, j;
    i = j = 0;
    while (from[i] != '\0') {
        if (from[i] == TAB)
            for (int n = 0; n < TAB_SIZE; ++n)
                to[j++] = BLANK;
        else {
            to[j] = from[i];
            ++j;
        }
        ++i;
    }
    to[j] = '\0';
}