// Write a function setbits(x,p,n,y) that returns x with the n bits that begin at
// position p set to the rightmost n bits of y, leaving the other bits unchanged.
// gcc -o a.o 02-06.c && ./a.o

#include <stdio.h>

unsigned setbits(unsigned x, unsigned p, unsigned n, unsigned y) {
    // Get the rightmost n bits of y.
  // e.g. n = 3
  // (~0 << n) gives us 11..11000
  // do a |~| operation on it and we get 
  // y & 00..00111 gives us the rightmost 3 bits of y.
    unsigned a = y & ~(~0U << n);

    // Put these bits in the right place. i.e. at position [p+n, p]
    a <<= p;

    // To set a bit to the given value we need to achieve this:
  // 0 ? 0 -> 0
  // 0 ? 1 -> 0
  // 1 ? 0 -> 1
  // 1 ? 1 -> 1
  // Obviously no operator can do this.
  // So we need to clear bits from x in the range of [p+n, p] first.
  // We need to do (x & 11..000..11), and how can we get 11..000..11?
  // We mentioned above that (~(~0 << n)) gave us 00..00111.
  // Just right shift it and do a |~| operation we can get 11..000..11.
    unsigned b = ~((~(~0U << n)) << p);

    // Do a |&| operation to clear the bits in the range [p+n, p]
    x = x & b;

    // Set bits from p through p+n in x to a.
    return x | a;
}

int main() {
    int x = 9713;	// 0010 0101 1111 0001
    int y = 3500;   // 0000 1101 1010 1100

    printf("Setbit result: %d", setbits(x, 8, 4, y)); // expecting 0010 1100 1111 0001 - 11505
}