// Write a program to "fold" long input lines into two or more shorter lines after the last non-blank character 
// that occurs before the n-th column of input.
// Make sure your program does something intelligent with very long lines, and if there are no blanks or tabs
// before the specified column.
// gcc -o a.o 01-22.c && cat text.txt | ./a.o

#include <stdio.h>
#include <string.h>

#define NEWLINE '\n'
#define TAB '\t'
#define BLANK ' '
#define MAXLEN 1000

int getLine(char line[], int lim);
void fold(char to[], char from[], int n);

int main() {
    char line[MAXLEN], foldedLine[MAXLEN];
    while (getLine(line, MAXLEN)) {
        fold(foldedLine, line, 80);
        for (int i = 0; i < strlen(foldedLine); ++i)
            putchar(foldedLine[i]);
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

void fold(char to[], char from[], int n) {
    int i, j, c, spaceholder;
    i = j = c = spaceholder = 0;
    while (from[i] != '\0') {
        ++c;
        if (from[i] == BLANK || from[i] == TAB) {
            spaceholder = i; // Record the last space/tab before n-th column.
        }
        if (c == n) {
            if (spaceholder == 0) // If it's a long line without blanks or tabs, separate it from the middle of the word.
                to[j++] = NEWLINE;
            else
                to[spaceholder] = NEWLINE;
            c = 0;
        } else {
            to[j++] = from[i++];
        }
    }
    to[j] = '\0';
}