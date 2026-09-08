#include <stdio.h>
#include <stdlib.h>

int k; // column index to sort by (global for the qsort comparator)

int compareRows(const void *a, const void *b) {
    const int *rowA = *(const int **)a;
    const int *rowB = *(const int **)b;
    return rowB[k] - rowA[k]; // descending order on column k
}

void sortTheStudents(int **score, int m, int n, int kk) {
    k = kk;
    qsort(score, m, sizeof(int *), compareRows);
}

static void printMatrix(int **mat, int m, int n) {
    printf("[");
    for (int i = 0; i < m; i++) {
        printf("[");
        for (int j = 0; j < n; j++) {
            printf("%d%s", mat[i][j], (j == n - 1) ? "" : ",");
        }
        printf("]%s", (i == m - 1) ? "" : ",");
    }
    printf("]\n");
}

int main(void) {
    // Sample 1
    int r0[] = {10, 6, 9, 1};
    int r1[] = {7, 5, 11, 2};
    int r2[] = {4, 8, 3, 15};
    int *mat1[] = {r0, r1, r2};
    sortTheStudents(mat1, 3, 4, 2);
    printMatrix(mat1, 3, 4); // [[7,5,11,2],[10,6,9,1],[4,8,3,15]]

    // Sample 2
    int s0[] = {3, 4};
    int s1[] = {5, 6};
    int *mat2[] = {s0, s1};
    sortTheStudents(mat2, 2, 2, 0);
    printMatrix(mat2, 2, 2); // [[5,6],[3,4]]

    return 0;
}
