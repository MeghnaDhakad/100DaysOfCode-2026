#include <stdio.h>

int main() {
    int coins[] = {1, 5, 10, 25, 50};
    int n = sizeof(coins) / sizeof(coins[0]);

    int amount;
    printf("Enter amount: ");
    scanf("%d", &amount);

    int count = 0;

    for (int i = n - 1; i >= 0; i--) {
        if (amount >= coins[i]) {
            count += amount / coins[i];
            amount %= coins[i];
        }
    }

    printf("Minimum number of coins = %d\n", count);

    return 0;
}