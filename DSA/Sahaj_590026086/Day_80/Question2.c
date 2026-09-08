#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPowerOfTwoOrZero(int n) {
    return n == 0 || (n > 0 && (n & (n - 1)) == 0);
}

int main() {
    printf("%s\n", isPowerOfTwoOrZero(0) ? "true" : "false");
    return 0;
}
