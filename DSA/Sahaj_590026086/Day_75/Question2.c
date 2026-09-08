#include <stdio.h>
#include <stdlib.h>

int minCostRing(int n, int* costs) {
    int total = 0;
    for (int i = 0; i < n; i++) total += costs[i];
    return total;
}

int main() {
    int c[] = {1, 2, 3, 4};
    printf("%d\n", minCostRing(4, c));
    return 0;
}
