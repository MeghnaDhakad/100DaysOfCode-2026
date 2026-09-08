#include <stdio.h>
#include <stdlib.h>

int turnOffRightmostSetBit(int n) {
    return n & (n - 1);
}

int main() {
    printf("%d\n", turnOffRightmostSetBit(12));
    return 0;
}
