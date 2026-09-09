//Given n items with their values and weights, and a knapsack with a fixed capacity, 
//select whole or fractional parts of items to maximize the total value using a greedy approach.
//Input: value = [60, 100, 120], weight = [10, 20, 30], capacity = 50. Output: 240.
#include <stdio.h>

struct Item {
    int value;
    int weight;
    double ratio;
};

int main() {
    int n, capacity;
    printf("Enter number of items: ");
    scanf("%d", &n);
    struct Item items[n];
    printf("Enter values of items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &items[i].value);
    }
    printf("Enter weights of items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &items[i].weight);
        items[i].ratio = (double)items[i].value / items[i].weight;
    }
    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (items[j].ratio < items[j + 1].ratio) {
                struct Item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
    double totalValue = 0.0;
    int remainingCapacity = capacity;
    for (int i = 0; i < n; i++) {
        if (remainingCapacity == 0)
            break;
        if (items[i].weight <= remainingCapacity) {
            totalValue += items[i].value;
            remainingCapacity -= items[i].weight;
        } 
        else {
            double fraction = (double)remainingCapacity / items[i].weight;
            totalValue += items[i].value * fraction;
            remainingCapacity = 0;
        }
    }
    printf("Maximum value = %.2lf\n", totalValue);
    return 0;
}