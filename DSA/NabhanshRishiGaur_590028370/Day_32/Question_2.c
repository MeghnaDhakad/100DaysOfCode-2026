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

void copyStack(Stack *src, Stack *dest) {
    Stack temp1, temp2;
    temp1.top = -1;
    temp2.top = -1;

    while (!isEmpty(src))
        push(&temp1, pop(src));

    while (!isEmpty(&temp1)) {
        int x = pop(&temp1);
        push(src, x);
        push(&temp2, x);
    }

    while (!isEmpty(&temp2))
        push(dest, pop(&temp2));
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
    Stack st, copy;
    st.top = -1;
    copy.top = -1;

    push(&st, 1);
    push(&st, 2);
    push(&st, 3);
    push(&st, 4);

    copyStack(&st, &copy);

    printf("Original Stack: ");
    printStack(&st);

    printf("Copied Stack: ");
    printStack(&copy);

    return 0;
}
