// The binary_search function below makes two tests inside the loop, when one would suffice (at the price of 
// more tests outside).
// Write a version with only one test inside the loop and measure the difference in run-time.
// gcc -o a.o 03-01.c && ./a.o

#include <stdio.h>
#include <time.h>

#define MAX_ELEMENTS 100000

// binary_search: find x in v[0] <= v[1] <= ... <= v[n-1]
int binary_search(int x, int v[], int n) {
    int l, r, m;
    l = 0;
    r = n - 1;
    while (l <= r) {
        m = (r - l) / 2 + l;
        if (v[m] < x) l = m + 1;
        else if (v[m] > x) r = m - 1;
        else return m;
    }
    return -1;
}

int binary_search_2(int x, int v[], int n) {
    int l, r, m;
    l = 0;
    r = n - 1;
    while (l <= r) {
        m = (r - l) / 2 + l;
        if (v[m] < x) l = m + 1;
        else r = m - 1;
    }
    if (v[l] == x) return l;
    return -1;
}

double now() {
    return ((double) clock()) / CLOCKS_PER_SEC;
}

int main() {
    int v[MAX_ELEMENTS];
    
    for (int i = 0; i < MAX_ELEMENTS; ++i)
        v[i] = i;
    
    double start;
    start = now();
    for (int i = 0; i < MAX_ELEMENTS; ++i)
        binary_search(i + 1, v, MAX_ELEMENTS);
    printf("Took binary_search   %f sec to find %d elements in an array of %d\n", now() - start, MAX_ELEMENTS, MAX_ELEMENTS);

    start = now();
    for (int i = 0; i < MAX_ELEMENTS; ++i)
        binary_search_2(i + 1, v, MAX_ELEMENTS);
    printf("Took binary_search_2 %f sec to find %d elements in an array of %d\n", now() - start, MAX_ELEMENTS, MAX_ELEMENTS);
}