#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* solve(char postfix[], int *idx) {
    char ch = postfix[(*idx)--];

    // Operand
    if (isalnum(ch)) {
        char *res = (char *)malloc(2);
        res[0] = ch;
        res[1] = '\0';
        return res;
    }

    char *right = solve(postfix, idx);
    char *left = solve(postfix, idx);

    int len = strlen(left) + strlen(right) + 2;
    char *res = (char *)malloc(len);

    res[0] = ch;
    res[1] = '\0';
    strcat(res, left);
    strcat(res, right);

    free(left);
    free(right);

    return res;
}

char* postfixToPrefix(char postfix[]) {
    int idx = strlen(postfix) - 1;
    return solve(postfix, &idx);
}

int main() {
    char postfix[] = "AB+CD-*";

    char *prefix = postfixToPrefix(postfix);
    printf("%s\n", prefix);

    free(prefix);
    return 0;
}
