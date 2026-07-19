#include <stdio.h>

#define MAX 100

typedef struct {
    int arr[MAX];
    int top;
} Stack;

void push(Stack *s, int x) {
    s->arr[++s->top] = x;
}

int pop(Stack *s) {
    return s->arr[s->top--];
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void insertAtBottom(Stack *s, int x) {
    Stack temp;
    temp.top = -1;

    while (!isEmpty(s))
        push(&temp, pop(s));

    push(s, x);
  
    while (!isEmpty(&temp))
        push(s, pop(&temp));
}

void printStack(Stack *s) {
    printf("[");
    for (int i = 0; i <= s->top; i++) {
        printf("%d", s->arr[i]);
        if (i != s->top)
            printf(",");
    }
    printf("]\n");
}

int main() {
    Stack s;
    s.top = -1;

    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    push(&s, 4);

    insertAtBottom(&s, 5);

    printStack(&s);

    return 0;
}
