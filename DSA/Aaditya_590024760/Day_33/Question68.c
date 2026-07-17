#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

void convertPostfixToPrefix(char* postfix) {
    int n = strlen(postfix);
    char* stack[n];
    int top = -1;

    for (int i = 0; i < n; i++) {
        if (!isOperator(postfix[i])) {
            char* operand = (char*)malloc(2 * sizeof(char));
            operand[0] = postfix[i];
            operand[1] = '\0';
            stack[++top] = operand;
        } else {
            char* op2 = stack[top--];
            char* op1 = stack[top--];

            char* expr = (char*)malloc((strlen(op1) + strlen(op2) + 2) * sizeof(char));
            expr[0] = postfix[i];
            expr[1] = '\0';
            strcat(expr, op1);
            strcat(expr, op2);

            stack[++top] = expr;

            free(op1);
            free(op2);
        }
    }

    printf("Prefix expression: %s\n", stack[top]);
    free(stack[top]);
}

int main() {
    char postfix[100];

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    printf("Postfix expression: %s\n", postfix);
    convertPostfixToPrefix(postfix);

    return 0;
}
