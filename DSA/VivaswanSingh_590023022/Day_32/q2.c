#include <stdio.h>

#define MAX 100

typedef struct
{
    int items[MAX];
    int top;
} Stack;

void initialize(Stack *stack)
{
    stack->top = -1;
}

int isEmpty(Stack *stack)
{
    return stack->top == -1;
}

int isFull(Stack *stack)
{
    return stack->top == MAX - 1;
}

void push(Stack *stack, int value)
{
    if (!isFull(stack))
    {
        stack->items[++stack->top] = value;
    }
}

int pop(Stack *stack)
{
    if (!isEmpty(stack))
    {
        return stack->items[stack->top--];
    }

    return -1;
}

void copyStack(Stack *source, Stack *destination)
{
    Stack temp;
    initialize(&temp);

    while (!isEmpty(source))
    {
        push(&temp, pop(source));
    }

    while (!isEmpty(&temp))
    {
        int value = pop(&temp);
        push(source, value);
        push(destination, value);
    }
}

void printStack(Stack *stack)
{
    for (int i = 0; i <= stack->top; i++)
    {
        printf("%d ", stack->items[i]);
    }

    printf("\n");
}

int main()
{
    Stack source, destination;

    initialize(&source);
    initialize(&destination);

    push(&source, 1);
    push(&source, 2);
    push(&source, 3);
    push(&source, 4);

    copyStack(&source, &destination);

    printStack(&destination);

    return 0;
}