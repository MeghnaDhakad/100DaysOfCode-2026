#include <stdio.h>
#include <stdlib.h>

int* deckArrangement(int n, int* returnSize) {
    int *deck = (int *)malloc(n * sizeof(int));
    int *queue = (int *)malloc(n * sizeof(int));

    int front = 0, rear = 0;

    for (int i = 0; i < n; i++)
        queue[rear++] = i;

    for (int card = 1; card <= n; card++) {
        int pos = queue[front++];
        deck[pos] = card;

        if (front < rear) {
            queue[rear++] = queue[front++];
        }
    }

    free(queue);
    *returnSize = n;
    return deck;
}

int main() {
    int n;
    scanf("%d", &n);

    int size;
    int *ans = deckArrangement(n, &size);

    for (int i = 0; i < size; i++)
        printf("%d ", ans[i]);

    free(ans);
    return 0;
}