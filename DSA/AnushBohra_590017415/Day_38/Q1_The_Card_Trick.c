#include <stdio.h>
#include <stdlib.h>

void cardTrick(int n, int* result) {
    int* queue = (int*)malloc(n * sizeof(int));
    int front = 0;
    int rear = 0;

    for (int i = 0; i < n; i++) {
        queue[rear++] = i;
    }

    for (int i = 1; i <= n; i++) {
        int idx = queue[front++];
        result[idx] = i;

        if (front < rear) {
            queue[rear++] = queue[front++];
        }
    }

    free(queue);
}

int main() {
    int n = 4;
    int* result = (int*)malloc(n * sizeof(int));

    cardTrick(n, result);

    printf("Output: [");
    for (int i = 0; i < n; i++) {
        printf("%d%s", result[i], (i == n - 1) ? "" : ", ");
    }
    printf("]\n");

    free(result);
    return 0;
}