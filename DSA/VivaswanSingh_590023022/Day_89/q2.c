#include <stdio.h>

int buyChoco(int* prices, int pricesSize, int money)
{
    int first = 1001;
    int second = 1001;

    for (int i = 0; i < pricesSize; i++)
    {
        if (prices[i] < first)
        {
            second = first;
            first = prices[i];
        }
        else if (prices[i] < second)
        {
            second = prices[i];
        }
    }

    if (first + second <= money)
        return money - first - second;

    return money;
}

int main()
{
    int prices[] = {1, 2, 2};
    int money = 3;

    int size = sizeof(prices) / sizeof(prices[0]);

    int result = buyChoco(prices, size, money);

    printf("%d\n", result);

    return 0;
}