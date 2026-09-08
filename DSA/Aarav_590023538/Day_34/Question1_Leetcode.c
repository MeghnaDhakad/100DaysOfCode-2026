#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int stack1[MAX];
    int stack2[MAX];
    int top1;
    int top2;
} MyQueue;

// Create and initialize the queue
MyQueue* myQueueCreate() {
    MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
    obj->top1 = -1;
    obj->top2 = -1;
    return obj;
}

// Push element into stack1
void myQueuePush(MyQueue* obj, int x) {
    obj->stack1[++obj->top1] = x;
}

// Remove and return the front element
int myQueuePop(MyQueue* obj) {
    // If stack2 is empty, move all elements from stack1 to stack2
    if (obj->top2 == -1) {
        while (obj->top1 != -1) {
            obj->stack2[++obj->top2] = obj->stack1[obj->top1--];
        }
    }
    // Pop from stack2 (front of queue)
    return obj->stack2[obj->top2--];
}

// Return the front element without removing it
int myQueuePeek(MyQueue* obj) {
    // Transfer elements only if stack2 is empty
    if (obj->top2 == -1) {
        while (obj->top1 != -1) {
            obj->stack2[++obj->top2] = obj->stack1[obj->top1--];
        }
    }
    // Top of stack2 is the front of the queue
    return obj->stack2[obj->top2];
}

// Check whether the queue is empty
bool myQueueEmpty(MyQueue* obj) {
    return (obj->top1 == -1 && obj->top2 == -1);
}

// Free allocated memory
void myQueueFree(MyQueue* obj) {
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 *
 * int param_2 = myQueuePop(obj);
 *
 * int param_3 = myQueuePeek(obj);
 *
 * bool param_4 = myQueueEmpty(obj);
 *
 * myQueueFree(obj);
 */

int main() {
    printf("Execution completed successfully.\n");
    return 0;
}
