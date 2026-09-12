#include <stdio.h>

int buyChoco(int* prices, int pricesSize, int money) {
    int min1 = 1001;
    int min2 = 1001;

    for (int i = 0; i < pricesSize; i++) {
        if (prices[i] < min1) {
            min2 = min1;
            min1 = prices[i];
        } else if (prices[i] < min2) {
            min2 = prices[i];
        }
    }

    int total = min1 + min2;

    if (total <= money) {
        return money - total;
    }

    return money;
}

int main() {
    int prices[] = {1, 2, 2};
    int money = 3;

    int n = sizeof(prices) / sizeof(prices[0]);

    printf("%d\n", buyChoco(prices, n, money));

    return 0;
}
