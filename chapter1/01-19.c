// Write a function |reverse(s)| that reverses the character string |s|.
// Use it to write a program that reverses its input a line at a time.
// gcc -o a.o 01-19.c && cat text.txt | ./a.o

#include <stdio.h>
#include <string.h>

#define NEWLINE '\n'
#define TAB '\t'
#define BLANK ' '
#define MAXLEN 1000

int getLine(char line[], int lim);
void reverse(char line[]);

int main() {
    int len = 0;
    char line[MAXLEN];
    while ((len = getLine(line, MAXLEN))) {
        reverse(line);
        for (int i = 0; i < len; ++i)
            putchar(line[i]);
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

void reverse(char line[]) {
    int l = 0, r = strlen(line) - 1;
    while (l < r) {
        char t = line[l];
        line[l] = line[r];
        line[r] = t;
        l++;
        r--;
    }
}