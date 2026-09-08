#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 100

// Stack to store strings
char stack[MAX][MAX];
int top = -1;

// Push a string onto the stack
void push(char str[]) {
    strcpy(stack[++top], str);
}

// Pop a string from the stack
char* pop() {
    return stack[top--];
}

int main() {
    char postfix[MAX];
    printf("Enter postfix expression: ");
    scanf("%s", postfix);
    int n = strlen(postfix);
    for (int i = 0; i < n; i++) {
        // If current character is an operand, push it as a string
        if (isalpha(postfix[i])) {
            char temp[2];
            temp[0] = postfix[i];
            temp[1] = '\0';
            push(temp);
        }
        else {
            // Pop the top two operands
            char op1[MAX], op2[MAX];
            strcpy(op2, pop());   // Second operand
            strcpy(op1, pop());   // First operand
            // Create prefix expression: operator + first operand + second operand
            char temp[MAX];
            temp[0] = postfix[i];
            temp[1] = '\0';
            strcat(temp, op1);
            strcat(temp, op2);
            // Push the new expression back onto the stack
            push(temp);
        }
    }
    // Final answer is at the top of the stack
    printf("Prefix Expression: %s\n", pop());
    return 0;
}
