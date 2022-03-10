// Write a function invert(x,p,n) that returns x with the n bits that begin at position p
// inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged.
// gcc -o a.o 02-07.c && ./a.o

#include <stdio.h>

unsigned invert(unsigned x, unsigned p, unsigned n) {
    // Use the |^| operator to achieve inversion.
    // 1 ^ 1 = 0
    // 1 ^ 0 = 1
    // Say p=2, n=3, we need 00..0011100
    int a = (~(~0U << n)) << p; // This is explained in 02-06.c
    return x ^ a;
}

int main() {
    int x = 9713;	// 0010 0101 1111 0001
	
	printf("invert result: %d", invert(x, 8, 4)); // expecting 0010 1010 1111 0001 - 10993
}