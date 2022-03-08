// Write a program to print all input lines that are longer than 80 characters
// gcc -o a.o 01-17.c && cat text.txt | ./a.o

#include <stdio.h>

#define NEWLINE '\n'
#define MINLEN 80
#define MAXLEN 1000

int getLine(char line[], int lim);

int main() {
    int len = 0;
    char line[MAXLEN];
    while ((len = getLine(line, MAXLEN))) {
        if (len > MINLEN) printf("%s", line);
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