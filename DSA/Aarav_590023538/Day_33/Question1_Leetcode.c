#include <stdio.h>
#include <stdlib.h>

char* removeOuterParentheses(char* s) {
    int n = strlen(s);
    // Allocate memory for the answer
    char* ans = (char*)malloc((n + 1) * sizeof(char));
    int depth = 0;   // Keeps track of current nesting level
    int j = 0;       // Index for answer string
    for (int i = 0; i < n; i++) {
        // If current character is '('
        if (s[i] == '(') {
            // If it is not the outermost opening bracket,
            // add it to the answer
            if (depth > 0) {
                ans[j++] = s[i];
            }
            // Increase nesting depth
            depth++;
        }
        else { // Current character is ')'
            // Decrease depth first
            depth--;
            // If it is not the outermost closing bracket,
            // add it to the answer
            if (depth > 0) {
                ans[j++] = s[i];
            }
        }
    }
    // Null terminate the answer string
    ans[j] = '\0';
    return ans;
}

int main() {
    printf("Execution completed successfully.\n");
    return 0;
}
