// Write a program |entab| that replaces strings of blanks by the minimum number of tabs and blanks to achieve the same spacing.
// Use the same tab stop as for |detab|(01-20.c).
// When either a tab or a single blank would suffice to reach a tab stop, which should be given preference?
// gcc -o a.o 01-21.c && cat text.txt | ./a.o

#include <stdio.h>
#include <string.h>

#define NEWLINE '\n'
#define TAB '\t'
#define BLANK ' '
#define TAB_SIZE 5
#define MAXLEN 1000

int getLine(char line[], int lim);
void entab(char to[], char from[]);

int main() {
    char line[MAXLEN], entabLine[MAXLEN];
    while (getLine(line, MAXLEN)) {
        entab(entabLine, line);
        for (int i = 0; i < strlen(entabLine); ++i)
            putchar(entabLine[i]);
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

void entab(char to[], char from[]) {
    int i, j, s;
    i = j = s = 0;
    while (from[i] != '\0') {
        if (from[i] == BLANK) {
            ++s;
            ++i;
        } else {
            int t = s / TAB_SIZE;
            s %= TAB_SIZE;
            while (t > 0) {
                to[j++] = TAB;
                --t;
            }
            while (s > 0) {
                to[j++] = BLANK;
                --s;
            }
            to[j++] = from[i++];
            s = 0;
        }
    }
    to[j] = '\0'; // don't forget the null character
}