#include <stdio.h>

int main() {
    int coins[100], n, amount;
    int count = 0;

    printf("Enter number of coin denominations: ");
    scanf("%d", &n);

    printf("Enter coin denominations: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }

    printf("Enter target amount: ");
    scanf("%d", &amount);

    // Sort coins in descending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (coins[i] < coins[j]) {
                int temp = coins[i];
                coins[i] = coins[j];
                coins[j] = temp;
            }
        }
    }

    printf("Coins used: ");

    // Greedy approach
    for (int i = 0; i < n; i++) {
        while (amount >= coins[i]) {
            amount -= coins[i];
            count++;
            printf("%d ", coins[i]);
        }
    }

    if (amount == 0) {
        printf("\nMinimum number of coins = %d\n", count);
    } else {
        printf("\nAmount cannot be formed using the given coins.\n");
    }

    return 0;
}
