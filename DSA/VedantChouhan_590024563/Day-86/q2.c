#include <stdio.h>
#include <stdlib.h>

struct Item {
    int value;
    int weight;
    double ratio;
};

int compare(const void *a, const void *b) {
    struct Item *x = (struct Item *)a;
    struct Item *y = (struct Item *)b;

    if (x->ratio < y->ratio)
        return 1;
    if (x->ratio > y->ratio)
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

    // Sort by highest value/weight ratio
    qsort(items, n, sizeof(struct Item), compare);

    double totalValue = 0.0;

    for (int i = 0; i < n; i++) {
        if (capacity >= items[i].weight) {
            // Take the whole item
            capacity -= items[i].weight;
            totalValue += items[i].value;
        } else {
            // Take the fraction that fits
            totalValue += items[i].ratio * capacity;
            capacity = 0;
            break;
        }
    }

    return totalValue;
}

int main() {
    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int value[n], weight[n];

    printf("Enter values: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value[i]);
    }

    printf("Enter weights: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &weight[i]);
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    double result = fractionalKnapsack(value, weight, n, capacity);

    printf("Maximum value: %.0f\n", result);

    return 0;
}