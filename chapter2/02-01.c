// Write a program to determine the ranges of char, short, int, and long variables, both signed and unsigned,
// by printing appropriate values from standard headers and by direct computation.
// Harder if you compute them: determine the ranges of the various floating-point types.
// gcc -o a.o 02-01.c && ./a.o

// short is often 16 bits
// long 32 bits
// int either 16 or 32 bits, the natural size for a particular machine
// but short is no longer than int, which is no longer than long

#include <stdio.h>
#include <limits.h>
#include <float.h>

int get_unsigned_short_bit();
int get_signed_short_bit();

int get_unsigned_int_bit();
int get_signed_int_bit();

int get_unsigned_long_bit();
int get_signed_long_bit();

int get_unsigned_long_long_bit();
int get_signed_long_long_bit();


int main() {
    printf("                [char] bits: %2d  range: %20d ~ %d\n", CHAR_BIT, CHAR_MIN, CHAR_MAX);
    printf("       [unsigned char] bits: %2d  range: %20u ~ %u\n", CHAR_BIT, (unsigned char)0, UCHAR_MAX);
    printf("         [signed char] bits: %2d  range: %20d ~ %d\n", CHAR_BIT, SCHAR_MIN, SCHAR_MAX);
    putchar('\n');
    printf("               [short] bits: %2d  range: %20d ~ %d\n", get_signed_short_bit(), SHRT_MIN, SHRT_MAX);
    printf("      [unsigned short] bits: %2d  range: %20u ~ %u\n", get_unsigned_short_bit(), 0U, USHRT_MAX);
    printf("        [signed short] bits: %2d  range: %20d ~ %d\n", get_signed_short_bit(), SHRT_MIN, SHRT_MAX);
    putchar('\n');
    printf("                 [int] bits: %2d  range: %20d ~ %d\n", get_signed_int_bit(), INT_MIN, INT_MAX);
    printf("        [unsigned int] bits: %2d  range: %20u ~ %u\n", get_unsigned_int_bit(), 0U, UINT_MAX);
    printf("          [signed int] bits: %2d  range: %20d ~ %d\n", get_signed_int_bit(), INT_MIN, INT_MAX);
    putchar('\n');
    printf("                [long] bits: %2d  range: %20ld ~ %ld\n", get_signed_long_bit(), LONG_MIN, LONG_MAX);
    printf("       [unsigned long] bits: %2d  range: %20lu ~ %lu\n", get_unsigned_long_bit(), 0L, ULONG_MAX);
    printf("         [signed long] bits: %2d  range: %20ld ~ %ld\n", get_signed_long_bit(), LONG_MIN, LONG_MAX);
    putchar('\n');
    printf("           [long long] bits: %2d  range: %20lld ~ %lld\n", get_signed_long_long_bit(), LLONG_MIN, LLONG_MAX);
    printf("  [unsigned long long] bits: %2d  range: %20llu ~ %llu\n", get_unsigned_long_long_bit(), 0LL, ULLONG_MAX);
    printf("    [signed long long] bits: %2d  range: %20lld ~ %lld\n", get_signed_long_long_bit(), LLONG_MIN, LLONG_MAX);
    putchar('\n');
    printf("               [float] bits: %2c  range: %20e ~ %e\n", '#', FLT_MIN, FLT_MAX);
    printf("              [double] bits: %2c  range: %20e ~ %e\n", '#', DBL_MIN, DBL_MAX);
    printf("         [long double] bits: %2c  range: %20e ~ %e\n", '#', LDBL_MIN, LDBL_MAX);
    putchar('\n');
}

int get_unsigned_short_bit() {
    unsigned short n = USHRT_MAX;
    int b = 0;
    while (n) {
        n = n >> 1;
        ++b;
    }
    return b;
}

int get_signed_short_bit() {
    signed short n = SHRT_MAX;
    int b = 1;
    while (n) {
        n = n >> 1;
        ++b;
    }
    return b;
}

int get_unsigned_int_bit() {
    unsigned int n = UINT_MAX;
    int b = 0;
    while (n) {
        n = n >> 1;
        ++b;
    }
    return b;
}

int get_signed_int_bit() {
    signed int n = INT_MAX;
    int b = 1;
    while (n) {
        n = n >> 1;
        ++b;
    }
    return b;
}

int get_unsigned_long_bit() {
    unsigned long n = ULONG_MAX;
    int b = 0;
    while (n) {
        n = n >> 1;
        ++b;
    }
    return b;
}

int get_signed_long_bit() {
    signed long n = LONG_MAX;
    int b = 1;
    while (n) {
        n = n >> 1;
        ++b;
    }
    return b;
}

int get_unsigned_long_long_bit() {
    unsigned long long n = ULLONG_MAX;
    int b = 0;
    while (n) {
        n = n >> 1;
        ++b;
    }
    return b;
}

int get_signed_long_long_bit() {
    signed long long n = LLONG_MAX;
    int b = 1;
    while (n) {
        n = n >> 1;
        ++b;
    }
    return b;
}