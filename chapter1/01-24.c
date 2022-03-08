// Write a program to check a C program for rudimentary syntax errors like unbalanced parentheses, brackets, and braces.
// Don't forget about quotes, both single and double, escape sequences, and comments.
// gcc -o a.o 01-24.c && cat 01-24.test.c | ./a.o

#include <stdio.h>
#include <string.h>

#define NEWLINE '\n'
#define CODE 1
#define SINGLE_COMMENT 2
#define BLOCK_COMMENT 3

int main() {
    int state, c, parentheses, brackets, braces, s_quotes, d_quotes, syntax_correct;

    state = CODE;
    parentheses = brackets = braces = 0;
    s_quotes = d_quotes = 1;
    syntax_correct = 1;

    while ((c = getchar()) != EOF) {
        switch (state) {
            case SINGLE_COMMENT:
                if (c == NEWLINE) state = CODE;
                break;
            case BLOCK_COMMENT:
                if (c == '*' && (c = getchar()) == '/')
                    state = CODE;
                break;
            case CODE:
                if (c == '\'' && d_quotes == 1) s_quotes *= -1;
                if (c == '"' && s_quotes == 1) d_quotes *= -1;
                if (c == '\\') {
                    c = getchar();
                    continue;
                }
                if (c == '/') {
                    c = getchar();
                    if (c == '/') state = SINGLE_COMMENT;
                    else if (c == '*') state = BLOCK_COMMENT;
                    continue;
                }
                if (c == '(') parentheses++;
                if (c == ')') parentheses--;
                if (c == '{') brackets++;
                if (c == '}') brackets--;
                if (c == '[') braces++;
                if (c == ']') braces--;
                break;
            default:
                break;
        }
    }

    if (parentheses) {
        printf("Mismatching parentheses\n");
        syntax_correct = 0;
    }
    if (brackets) {
        printf("Mismatching brackets\n");
        syntax_correct = 0;
    }
    if (braces) {
        printf("Mismatching braces\n");
        syntax_correct = 0;
    }
    if (s_quotes != 1) {
        printf("Mismatching single quotes\n");
        syntax_correct = 0;
    }
    if (d_quotes != 1) {
        printf("Mismatching double quotes\n");
        syntax_correct = 0;
    }
    if (syntax_correct)
        printf("Syntax appears to be correct\n");

}