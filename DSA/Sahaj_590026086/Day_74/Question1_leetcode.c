#include <stdio.h>
#include <stdlib.h>

int findParent(int* parent, int i) {
    if (parent[i] == i) return i;
    return parent[i] = findParent(parent, parent[i]);
}

long long countPairs(int n, int** edges, int edgesSize, int* edgesColSize) {
    int* parent = (int*)malloc(n * sizeof(int));
    int* compSize = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) parent[i] = i;
    for (int i = 0; i < edgesSize; i++) {
        int rootU = findParent(parent, edges[i][0]);
        int rootV = findParent(parent, edges[i][1]);
        if (rootU != rootV) parent[rootU] = rootV;
    }
    for (int i = 0; i < n; i++) compSize[findParent(parent, i)]++;
    long long totalPairs = 0, remaining = n;
    for (int i = 0; i < n; i++) {
        if (compSize[i] > 0) {
            totalPairs += (long long)compSize[i] * (remaining - compSize[i]);
            remaining -= compSize[i];
        }
    }
    free(parent); free(compSize);
    return totalPairs;
}

int main() {
    int e1[] = {0, 1}, e2[] = {0, 2}, e3[] = {1, 2};
    int* edges[] = {e1, e2, e3};
    int col = 2;
    printf("%lld\n", countPairs(7, edges, 3, &col));
    return 0;
}
