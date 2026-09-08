#include <stdio.h>
#include <stdlib.h>

int countSetBits(int n) {
    int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

int main() {
    printf("%d\n", countSetBits(7));
    return 0;
}
