#include <stdio.h>
#include <string.h>

int minLength(char s[]) {
    char stack[101];
    int top = -1;

    for (int i = 0; s[i] != '\0'; i++) {
        if (top >= 0 &&
            ((stack[top] == 'A' && s[i] == 'B') ||
             (stack[top] == 'C' && s[i] == 'D'))) {
            top--;      // Remove "AB" or "CD"
        } else {
            stack[++top] = s[i];
        }
    }
    return top + 1;
}

int main() {
    char s[101];

    printf("Enter the string: ");
    scanf("%s", s);

    printf("Minimum Length: %d\n", minLength(s));
    return 0;
}