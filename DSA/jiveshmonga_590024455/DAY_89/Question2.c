int buyChoco(int* prices, int pricesSize, int money) {
    int first = 1000000;
    int second = 1000000;

    for (int i = 0; i < pricesSize; i++) {
        if (prices[i] < first) {
            second = first;
            first = prices[i];
        } else if (prices[i] < second) {
            second = prices[i];
        }
    }

    int cost = first + second;

    if (cost <= money)
        return money - cost;

    return money;
}