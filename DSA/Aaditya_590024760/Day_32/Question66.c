#include <stdio.h>

void push(int* stack, int* top, int val) {
    stack[++(*top)] = val;
}

int pop(int* stack, int* top) {
    return stack[(*top)--];
}

int peek(int* stack, int top) {
    return stack[top];
}

int isEmpty(int top) {
    return top == -1;
}

void copyStack(int* src, int srcTop, int* dest, int* destTop, int* temp, int* tempTop) {

    // step 1: pop src into temp (reverses order)
    while (!isEmpty(srcTop)) {
        push(temp, tempTop, pop(src, &srcTop));
    }

    // step 2: pop temp into dest (restores original order)
    while (!isEmpty(*tempTop)) {
        int val = pop(temp, tempTop);
        push(dest, destTop, val);
    }
}

int main() {
    int n;

    printf("Enter size of stack: ");
    scanf("%d", &n);

    int src[n], dest[n], temp[n];
    int srcTop = -1, destTop = -1, tempTop = -1;

    printf("Enter elements (bottom to top): ");
    for (int i = 0; i < n; i++)
        push(src, &srcTop, 0), scanf("%d", &src[srcTop]);

    printf("\nOriginal stack (top to bottom): ");
    for (int i = srcTop; i >= 0; i--)
        printf("%d ", src[i]);

    copyStack(src, srcTop, dest, &destTop, temp, &tempTop);

    printf("\nCopied stack   (top to bottom): ");
    for (int i = destTop; i >= 0; i--)
        printf("%d ", dest[i]);
    printf("\n");

    return 0;
}
