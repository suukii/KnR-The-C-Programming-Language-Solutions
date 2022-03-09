// Write a function rightrot(x,n) that returns the value of the integer x rotated
// to the right by n bit positions.
// gcc -o a.o 02-08.c && ./a.o

#include <stdio.h>
#include <limits.h>

unsigned rightrot(unsigned x, unsigned n) {
    // Get the leftmost n bits, a.
    unsigned a = ~(~0U >> n) & x;
    // Move those bits to the leftmost position.
    a >>= (sizeof(unsigned) * CHAR_BIT - n);
    // Shift the value of x left by n positions.
    x <<= n;
    // Set the rightmost n bits of x to a.
    return x | a;
}

int main() {
    unsigned int x = 0xBEEFCAFE; // 1011 1110 1110 1111 1100 1010 1111 1110
    printf("rightrot result: %u\n", rightrot(x, 4)); // expecting 1110 1110 1111 1100 1010 1111 1110 1011 -> 4009537515
}