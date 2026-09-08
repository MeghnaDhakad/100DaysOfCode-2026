#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

// Push an element onto the stack
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = value;
}

// Pop the top element from the stack
int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

// Insert an element at the bottom of the stack
void insertAtBottom(int x) {
    // If stack is empty, insert the element
    if (top == -1) {
        push(x);
        return;
    }
    // Remove the top element
    int temp = pop();
    // Recursively insert x at the bottom
    insertAtBottom(x);
    // Push the removed element back
    push(temp);
}

// Display the stack from bottom to top
void display() {
    printf("Updated Stack: ");
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int n, x;

    // Take number of elements
    printf("Enter number of elements in stack: ");
    scanf("%d", &n);

    printf("Enter stack elements (bottom to top): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &stack[i]);
    }
    top = n - 1;

    // Take the element to insert
    printf("Enter element to insert at bottom: ");
    scanf("%d", &x);

    // Insert the element at the bottom
    insertAtBottom(x);

    // Print the updated stack
    display();

    return 0;
}
