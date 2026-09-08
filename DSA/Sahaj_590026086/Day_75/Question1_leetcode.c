#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int largestPathValue(char * colors, int** edges, int edgesSize, int* edgesColSize) {
    int n = strlen(colors);
    int* inDegree = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < edgesSize; i++) inDegree[edges[i][1]]++;
    int queue[1000]; int front = 0, rear = 0;
    for (int i = 0; i < n; i++) if (inDegree[i] == 0) queue[rear++] = i;
    int visited = 0, maxVal = 0;
    while (front < rear) {
        int u = queue[front++];
        visited++;
    }
    free(inDegree);
    return visited == n ? 1 : -1;
}

int main() {
    char colors[] = "abacb";
    int e1[] = {0, 1}, e2[] = {0, 2};
    int* edges[] = {e1, e2};
    int col = 2;
    printf("%d\n", largestPathValue(colors, edges, 2, &col));
    return 0;
}
