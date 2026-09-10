#include <stdio.h>

int minCoins(int coins[], int n, int amount) {
    int count = 0;

    for (int i = n - 1; i >= 0; i--) {
        while (amount >= coins[i]) {
            amount -= coins[i];
            count++;
        }
    }

    if (amount != 0)
        return -1;

    return count;
}

int main() {
    int coins[] = {1, 5, 10, 25, 50};
    int amount = 87;
    int n = 5;

    printf("%d\n", minCoins(coins, n, amount));

    return 0;
}