#include <stdlib.h>

#define MAXSIZE 10005

typedef struct {
    int data[MAXSIZE];
    int front, rear, size;
} Queue;

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

void enqueue(Queue *q, int x) {
    q->rear = (q->rear + 1) % MAXSIZE;
    q->data[q->rear] = x;
    q->size++;
}

int dequeue(Queue *q) {
    int val = q->data[q->front];
    q->front = (q->front + 1) % MAXSIZE;
    q->size--;
    return val;
}

int peekFront(Queue *q) {
    return q->data[q->front];
}

typedef struct {
    Queue q;
} RecentCounter;

// Initialize the counter (starts empty)
void recentCounterInit(RecentCounter *rc) {
    initQueue(&rc->q);
}

// Push t, then pop all timestamps older than t - 3000, return window size
int recentCounterPing(RecentCounter *rc, int t) {
    enqueue(&rc->q, t);
    while (peekFront(&rc->q) < t - 3000) {
        dequeue(&rc->q);
    }
    return rc->q.size;
}

/**
 * Your RecentCounter struct will be instantiated and called as such:
 * RecentCounter rc;
 * recentCounterInit(&rc);
 * int result = recentCounterPing(&rc, t);
 */

int main() {
    printf("Execution completed successfully.\n");
    return 0;
}
