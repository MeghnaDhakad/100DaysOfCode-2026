#include <stdio.h>
#include <stdlib.h>

int wizardMaster(int* powers, int n) {
    int maxP = powers[0];
    for (int i = 1; i < n; i++) if (powers[i] > maxP) maxP = powers[i];
    return maxP;
}

int main() {
    int p[] = {10, 45, 23, 89, 34};
    printf("%d\n", wizardMaster(p, 5));
    return 0;
}
