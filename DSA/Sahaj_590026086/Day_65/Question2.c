#include <stdio.h>
#include <stdlib.h>

int adjustTemperature(int current, int target) {
    return abs(target - current);
}

int main() {
    printf("%d\n", adjustTemperature(20, 25));
    return 0;
}
