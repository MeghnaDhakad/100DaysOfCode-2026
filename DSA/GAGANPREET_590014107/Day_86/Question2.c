#include <stdio.h>
#include <stdlib.h>

struct Item {
    int value;
    int weight;
    double ratio;
};

int compare(const void *a, const void *b) {
    struct Item *item1 = (struct Item *)a;
    struct Item *item2 = (struct Item *)b;

    if (item1->ratio < item2->ratio)
        return 1;
    else if (item1->ratio > item2->ratio)
        return -1;

    return 0;
}

double fractionalKnapsack(int value[], int weight[], int n, int capacity) {
    struct Item items[n];

    // Calculate value/weight ratio
    for (int i = 0; i < n; i++) {
        items[i].value = value[i];
        items[i].weight = weight[i];
        items[i].ratio = (double)value[i] / weight[i];
    }

    // Sort by ratio in descending order
    qsort(items, n, sizeof(struct Item), compare);

    double totalValue = 0.0;

    for (int i = 0; i < n; i++) {

        if (capacity >= items[i].weight) {
            // Take complete item
            capacity -= items[i].weight;
            totalValue += items[i].value;
        }
        else {
            // Take fractional part
            totalValue += items[i].ratio * capacity;
            break;
        }
    }

    return totalValue;
}

int main() {
    int value[] = {60, 100, 120};
    int weight[] = {10, 20, 30};
    int capacity = 50;

    int n = sizeof(value) / sizeof(value[0]);

    double result = fractionalKnapsack(value, weight, n, capacity);

    printf("Maximum value = %.2f\n", result);

    return 0;
}
