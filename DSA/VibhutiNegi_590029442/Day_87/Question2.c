#include <stdio.h>
int main() {
    int n, amount;
    scanf("%d", &n);
    int coins[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }
    scanf("%d", &amount);
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (coins[i] > coins[j]) {
                int temp = coins[i];
                coins[i] = coins[j];
                coins[j] = temp;
            }
        }
    }
    int count = 0;
    for (int i = n - 1; i >= 0; i--) {
        while (amount >= coins[i]) {
            amount = amount - coins[i];
            count++;
        }
    }
    if (amount != 0) {
        printf("-1");
    }
    else {
        printf("%d", count);
    }
    return 0;
}