#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}

int minCoins(int coins[], int n, int amount) {
    // Sort coins in descending order
    qsort(coins, n, sizeof(int), compare);

    int count = 0;

    for (int i = 0; i < n; i++) {
        while (amount >= coins[i]) {
            amount -= coins[i];
            count++;
        }
    }

    // If amount is still left, it cannot be formed
    if (amount != 0)
        return -1;

    return count;
}

int main() {
    int n, amount;

    printf("Enter number of coin denominations: ");
    scanf("%d", &n);

    int coins[n];

    printf("Enter coin denominations: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }

    printf("Enter target amount: ");
    scanf("%d", &amount);

    int result = minCoins(coins, n, amount);

    if (result == -1)
        printf("Amount cannot be formed.\n");
    else
        printf("Minimum number of coins: %d\n", result);

    return 0;
}