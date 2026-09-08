#include <stdio.h>
#include <stdlib.h>

int shortestChasePath(int n, int m) {
    return n + m - 2;
}

int main() {
    printf("%d\n", shortestChasePath(3, 3));
    return 0;
}
