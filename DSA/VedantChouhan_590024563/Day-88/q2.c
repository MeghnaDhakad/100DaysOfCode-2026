#include <stdio.h>

int buyChoco(int prices[], int pricesSize, int money) {
    int min1 = 1001;
    int min2 = 1001;

    for (int i = 0; i < pricesSize; i++) {
        if (prices[i] < min1) {
            min2 = min1;
            min1 = prices[i];
        }
        else if (prices[i] < min2) {
            min2 = prices[i];
        }
    }

    int cost = min1 + min2;

    if (cost <= money)
        return money - cost;

    return money;
}

int main() {
    int n, money;

    printf("Enter number of chocolates: ");
    scanf("%d", &n);

    int prices[n];

    printf("Enter chocolate prices: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &prices[i]);
    }

    printf("Enter money: ");
    scanf("%d", &money);

    printf("Remaining money: %d\n",
           buyChoco(prices, n, money));

    return 0;
}