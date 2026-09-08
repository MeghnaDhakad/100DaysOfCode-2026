#include <stdio.h>
#include <stdlib.h>

int minLength(char* s) {
    // Stack to store characters
    char stack[101];
    int top = -1;
    // Traverse the given string
    for (int i = 0; s[i] != '\0'; i++) {
        // Check if the top of the stack and current character
        // form "AB" or "CD"
        if (top >= 0 &&
            ((stack[top] == 'A' && s[i] == 'B') ||
             (stack[top] == 'C' && s[i] == 'D'))) {
            // Remove the matching pair
            top--;
        } else {
            // Otherwise, push the current character onto the stack
            stack[++top] = s[i];
        }
    }
    // Remaining characters in the stack
    // represent the minimum possible string length
    return top + 1;
}

int main() {
    printf("Execution completed successfully.\n");
    return 0;
}
