// In a two's complement number system, x &= (x - 1) deletes the rightmost 1-bit in x.
// Explain why.
// Use this observation to write a faster version of bitcount.
// gcc -o a.o 02-09.c && ./a.o

// If x is odd, e.g. 1111 0011
//       then x-1 is 1111 0010
// x-1 has the same bit representation as x except the rightmost bit is 0 instead of 1.
// In this case (x & (x-1)) == (x-1). The rightmost 1-bit is deleted.

// If x is even, e.g. 1001 1000
//        then x-1 is 1001 0111
// the representation of x-1 has the rightmost zeros of x becoming ones
// and the rightmost one becoming a zero.
// In this case (x & (x-1)) clears the rightmost 1-bit in x and the rightmost 1-bits from (x-1).

#include <stdio.h>

// A slower version of bitcount is impletemented 
// by shifting the value of x right by 1 position at a time.
unsigned bitcount_slow(int x) {
    unsigned b = 0;
    while (x) {
        if (x & 1U) ++b;
        x >>= 1;
    }
    return b;
}

// The fast version of bitcount.
unsigned bitcount(int x) {
    unsigned b = 0;
    while (x) {
        ++b;
        x &= (x - 1);
    }
    return b;
}

int main() {
    int a = 0b101001101001;
    int b = 0b011011010110;
    printf("bits of %d is %d\n", a, bitcount(a)); // expecting 6
    printf("bits of %d is %d\n", b, bitcount(b)); // expecting 7
}