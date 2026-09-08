#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int verifyPasscode(char* code) {
    int len = strlen(code);
    int sum = 0;
    for (int i = 0; i < len; i++) sum += code[i];
    return sum;
}

int main() {
    char code[] = "ABC123";
    printf("%d\n", verifyPasscode(code));
    return 0;
}
