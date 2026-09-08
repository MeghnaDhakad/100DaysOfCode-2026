#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 105

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

typedef struct {
    Queue q;
} MyStack;

// Initialize the stack
void myStackInit(MyStack *st) {
    initQueue(&st->q);
}

// Push x, then rotate so x moves to the front -> O(n)
void myStackPush(MyStack *st, int x) {
    enqueue(&st->q, x);
    int n = st->q.size;
    for (int i = 0; i < n - 1; i++)
        enqueue(&st->q, dequeue(&st->q));
}

// Remove and return the top element
int myStackPop(MyStack *st) {
    return dequeue(&st->q);
}

// Return the top element without removing it
int myStackTop(MyStack *st) {
    return st->q.data[st->q.front];
}

// Check whether the stack is empty
int myStackEmpty(MyStack *st) {
    return st->q.size == 0;
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack st;
 * myStackInit(&st);
 * myStackPush(&st, x);
 *
 * int param_2 = myStackPop(&st);
 *
 * int param_3 = myStackTop(&st);
 *
 * int param_4 = myStackEmpty(&st);
 */

int main() {
    printf("Execution completed successfully.\n");
    return 0;
}
