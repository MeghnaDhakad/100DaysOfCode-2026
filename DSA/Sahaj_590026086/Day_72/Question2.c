#include <stdio.h>
#include <stdlib.h>

int minSteps(int* path, int n) {
    return n > 0 ? n - 1 : 0;
}

int main() {
    int path[] = {1, 2, 3, 4};
    printf("%d\n", minSteps(path, 4));
    return 0;
}
