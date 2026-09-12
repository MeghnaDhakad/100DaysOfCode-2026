//Buy the two cheapest chocolates if you have enough money and return the remaining amount; otherwise, keep all your money.
//Input:prices = [1,2,2], money = 3. Output:0.
#include <stdio.h>

int buyChocolates(int* prices, int pricesSize, int money) {
    int min1 = 1000000, min2 = 1000000;
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
    printf("Enter prices: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &prices[i]);
    }
    printf("Enter money: ");
    scanf("%d", &money);
    int remaining = buyChocolates(prices, n, money);
    printf("Remaining money: %d\n", remaining);
return 0;
}