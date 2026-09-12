#include <stdio.h>
int buyChoco(int prices[], int size, int money) {
    int min1 = prices[0];
    int min2 = prices[1];
    if (min1 > min2) {
        int temp = min1;
        min1 = min2;
        min2 = temp;
    }
    for (int i = 2; i < size; i++) {
        if (prices[i] < min1) {
            min2 = min1;
            min1 = prices[i];
        }
        else if (prices[i] < min2) {
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
    int size = sizeof(prices) / sizeof(prices[0]);
    int result = buyChoco(prices, size, money);
    printf("Money left = %d\n", result);
    return 0;
}