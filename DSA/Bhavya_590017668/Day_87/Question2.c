#include <stdio.h>
#include <stdbool.h>

int minCoins(int* coins, int coinsSize, int amount) {
    int count = 0;

    for (int i = coinsSize - 1; i >= 0; i--) {
        while (amount >= coins[i]) {
            amount -= coins[i];
            count++;
        }
    }

    return amount == 0 ? count : -1;
}

int main() {
    int coins[] = {1, 5, 10, 25};
    int coinsSize = 4;
    int amount = 63;

    printf("Minimum number of coins: %d\n", minCoins(coins, coinsSize, amount));

    return 0;
}