#include <stdio.h>
#include <stdlib.h>

char* removeDuplicates(char* s) {
    int n = strlen(s);
    // Create a stack to store characters
    char *stack = (char *)malloc((n + 1) * sizeof(char));
    int top = -1;

    // Traverse the string
    for (int i = 0; i < n; i++) {
        // If current character matches the top of the stack,
        // remove the duplicate by popping
        if (top != -1 && stack[top] == s[i]) {
            top--;
        }
        else {
            // Otherwise push the current character
            stack[++top] = s[i];
        }
    }

    // Add null character to make it a valid string
    stack[top + 1] = '\0';

    // Return the final string
    return stack;
}

int main() {
    printf("Execution completed successfully.\n");
    return 0;
}
