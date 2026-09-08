#include <stdio.h>
#include <stdlib.h>

int hammingDistance(int x, int y) {
    int xorVal = x ^ y, dist = 0;
    while (xorVal) {
        dist += xorVal & 1;
        xorVal >>= 1;
    }
    return dist;
}

int main() {
    printf("%d\n", hammingDistance(1, 4));
    return 0;
}
