#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

int main() {
    printf("%s\n", isPowerOfTwo(16) ? "true" : "false");
    return 0;
}
