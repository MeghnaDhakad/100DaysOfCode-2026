#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int priority;
    int index;
} Doc;

int printerQueue(int *priorities, int n, int location) {
    // Capacity n is sufficient: documents only cycle, never duplicate
    Doc *queue = (Doc *)malloc(n * sizeof(Doc));
    int front = 0, rear = n - 1, size = n;

    for (int i = 0; i < n; i++) {
        queue[i].priority = priorities[i];
        queue[i].index = i;
    }

    // count of each priority (1-9) still waiting in the queue
    int count[10] = {0};
    for (int i = 0; i < n; i++) {
        count[priorities[i]]++;
    }

    int minutes = 0;

    while (size > 0) {
        Doc d = queue[front];
        front = (front + 1) % n;
        size--;

        // find current max priority in O(9)
        int maxPriority = 0;
        for (int p = 9; p >= 1; p--) {
            if (count[p] > 0) { maxPriority = p; break; }
        }

        if (d.priority < maxPriority) {
            // move to back of the queue
            rear = (rear + 1) % n;
            queue[rear] = d;
            size++;
        } else {
            // print it
            minutes++;
            count[d.priority]--;
            if (d.index == location) {
                free(queue);
                return minutes;
            }
        }
    }

    free(queue);
    return -1; // unreachable if location is valid
}

int main() {
    int priorities[] = {2, 1, 3, 2};
    int n = sizeof(priorities) / sizeof(priorities[0]);
    int location = 2;
    printf("Minute printed: %d\n", printerQueue(priorities, n, location));
    return 0;
}
