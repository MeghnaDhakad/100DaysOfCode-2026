#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool isValid(char* s) {
    int n = strlen(s);
    // Create a stack to store opening brackets
    char *stack = (char *)malloc((n + 1) * sizeof(char));
    int top = -1;

    // Traverse the string
    for (int i = 0; i < n; i++) {
        // If current character is an opening bracket, push it
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            stack[++top] = s[i];
        }
        else {
            // If stack is empty, closing bracket has no match
            if (top == -1) {
                free(stack);
                return false;
            }
            // Check if the top of stack matches current closing bracket
            if ((s[i] == ')' && stack[top] == '(') ||
                (s[i] == '}' && stack[top] == '{') ||
                (s[i] == ']' && stack[top] == '[')) {
                // Matching pair found, pop the opening bracket
                top--;
            }
            else {
                // Brackets do not match
                free(stack);
                return false;
            }
        }
    }

    // String is valid only if stack becomes empty
    bool ans = (top == -1);
    free(stack);
    return ans;
}

int main() {
    printf("Execution completed successfully.\n");
    return 0;
}
