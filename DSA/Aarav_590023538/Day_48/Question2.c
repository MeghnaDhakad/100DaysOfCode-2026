#include <stdio.h>
#include <stdlib.h>

int cmpDesc(const void *a, const void *b) {
    long long x = *(const long long *)a;
    long long y = *(const long long *)b;
    if (x < y) return 1;
    if (x > y) return -1;
    return 0;
}

// Reconstructs array a of length n from array b of all pairwise minimums.
// b is sorted in place; caller must free the returned array.
long long* reconstructArray(long long *b, int bn, int n) {
    qsort(b, bn, sizeof(long long), cmpDesc);

    long long *a = malloc(n * sizeof(long long));
    int ptr = 0;
    for (int j = 1; j < n; j++) {
        a[j] = b[ptr];
        ptr += j;
    }
    a[0] = a[1] + 1; // any value >= a[1] works; +1 keeps it strictly the largest

    return a;
}

static void printArray(long long *arr, int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%lld%s", arr[i], (i == n - 1) ? "" : ", ");
    }
    printf("]\n");
}

int main(void) {
    // Sample 1
    long long b1[] = {5};
    long long *a1 = reconstructArray(b1, 1, 2);
    printArray(a1, 2); // [6, 5] — any array with min(a[0],a[1]) == 5 is valid

    // Sample 2
    long long b2[] = {4, 2, 2};
    long long *a2 = reconstructArray(b2, 3, 3);
    printArray(a2, 3); // [5, 4, 2]

    free(a1);
    free(a2);
    return 0;
}
