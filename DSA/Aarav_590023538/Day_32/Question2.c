#include <stdio.h>
#define MAX 100

// Stack structure
struct Stack {
    int arr[MAX];
    int top;
};

// Initialize stack
void init(struct Stack *s) {
    s->top = -1;
}

// Check if stack is empty
int isEmpty(struct Stack *s) {
    return s->top == -1;
}

// Push an element onto the stack
void push(struct Stack *s, int value) {
    s->arr[++(s->top)] = value;
}

// Pop the top element from the stack
int pop(struct Stack *s) {
    return s->arr[(s->top)--];
}

// Return the top element without removing it
int peek(struct Stack *s) {
    return s->arr[s->top];
}

// Copy elements from one stack to another
void copyStack(struct Stack *original, struct Stack *copy) {
    struct Stack temp;
    // Initialize temporary stack
    init(&temp);
    init(copy);
    // Move all elements from original to temporary stack
    while (!isEmpty(original)) {
        push(&temp, pop(original));
    }
    // Move elements back to original
    // and simultaneously copy them into the new stack
    while (!isEmpty(&temp)) {
        int value = pop(&temp);
        push(original, value); // Restore original stack
        push(copy, value);     // Copy into new stack
    }
}

// Display stack from bottom to top
void display(struct Stack *s) {
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}

int main() {
    struct Stack st, copiedStack;
    init(&st);
    // Push elements into the original stack
    push(&st, 1);
    push(&st, 2);
    push(&st, 3);
    push(&st, 4);
    // Copy the stack
    copyStack(&st, &copiedStack);
    printf("Original Stack: ");
    display(&st);
    printf("Copied Stack: ");
    display(&copiedStack);
    return 0;
}
