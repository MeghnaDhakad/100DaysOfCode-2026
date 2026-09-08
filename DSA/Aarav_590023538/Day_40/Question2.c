#include <stdio.h>
#include <stdlib.h>

/* Returns a malloc'd array of length (n - k + 1) with the max of every
   window of size k. Caller must free the returned array. */
int* slidingWindowMax(int* temps, int n, int k, int* outSize) {
    int* result = malloc((n - k + 1) * sizeof(int));
    int* dq = malloc(n * sizeof(int)); /* stores indices, values decreasing */
    int head = 0, tail = 0;            /* deque occupies dq[head..tail-1] */
    int ri = 0;

    for (int i = 0; i < n; i++) {
        /* drop indices that fell out of the window */
        while (head < tail && dq[head] <= i - k) head++;

        /* drop indices whose values are <= current value */
        while (head < tail && temps[dq[tail - 1]] <= temps[i]) tail--;

        dq[tail++] = i;

        if (i >= k - 1) {
            result[ri++] = temps[dq[head]];
        }
    }

    free(dq);
    *outSize = ri;
    return result;
}

static void printArray(int* arr, int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d%s", arr[i], (i == n - 1) ? "" : ", ");
    }
    printf("]\n");
}

int main(void) {
    int t1[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int t2[] = {9, 11, 8, 5, 7, 10};
    int t3[] = {4, 4, 4, 4};

    int size;
    int* r1 = slidingWindowMax(t1, 8, 3, &size);
    printArray(r1, size); free(r1);   /* [3, 3, 5, 5, 6, 7] */

    int* r2 = slidingWindowMax(t2, 6, 2, &size);
    printArray(r2, size); free(r2);   /* [11, 11, 8, 7, 10] */

    int* r3 = slidingWindowMax(t3, 4, 2, &size);
    printArray(r3, size); free(r3);   /* [4, 4, 4] */

    return 0;
}
