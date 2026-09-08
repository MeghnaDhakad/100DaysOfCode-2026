#include <stdio.h>
#include <string.h>

int main() {
    char str[100];

    // Take input string
    printf("Enter a string: ");
    scanf("%s", str);

    int n = strlen(str);

    // Stack to store characters
    char stack[100];
    int top = -1;

    // Push all characters of the string onto the stack
    for (int i = 0; i < n; i++) {
        stack[++top] = str[i];
    }

    // Pop characters from the stack to get the reversed string
    printf("Reversed string: ");
    while (top != -1) {
        printf("%c", stack[top--]);
    }
    printf("\n");

    return 0;
}
