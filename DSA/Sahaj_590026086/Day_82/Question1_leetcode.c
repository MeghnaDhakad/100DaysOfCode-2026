#include <stdio.h>
#include <stdlib.h>

int numberOfSteps(int num) {
    int steps = 0;
    while (num > 0) {
        if (num % 2 == 0) num /= 2;
        else num -= 1;
        steps++;
    }
    return steps;
}

int main() {
    printf("%d\n", numberOfSteps(14));
    return 0;
}
