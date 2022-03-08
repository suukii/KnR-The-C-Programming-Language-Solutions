// Write a program to print the longest line of its input.
// gcc -o a.o 01-16.c && cat text.txt | ./a.o

#include <stdio.h>

#define NEWLINE '\n'
#define MAXLEN 100

int getLine(char line[], int lim);
void copy(char to[], char from[]);

int main() {
    int len, max_len;
    char line[MAXLEN], longest[MAXLEN];
    len = max_len = 0;
    while ((len = getLine(line, MAXLEN))) {
        if (len > max_len) {
            max_len = len;
            copy(longest, line);
        }
    }
    if (max_len > 0) printf("%s", longest);
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

void copy(char to[], char from[]) {
    int i = 0;
    while ((to[i] = from[i]) != '\0') {
        ++i;
    }
}