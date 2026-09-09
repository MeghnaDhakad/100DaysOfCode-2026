#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int weight;
    double ratio;
} Item;

int compare(const void *a, const void *b) {
    Item *x = (Item *)a;
    Item *y = (Item *)b;

    if (x->ratio < y->ratio)
        return 1;
    if (x->ratio > y->ratio)
        return -1;
    return 0;
}

double fractionalKnapsack(int value[], int weight[], int n, int capacity) {
    Item items[n];

    for (int i = 0; i < n; i++) {
        items[i].value = value[i];
        items[i].weight = weight[i];
        items[i].ratio = (double)value[i] / weight[i];
    }

    // Sort by value/weight ratio
    qsort(items, n, sizeof(Item), compare);

    double totalValue = 0.0;

    for (int i = 0; i < n && capacity > 0; i++) {
        if (items[i].weight <= capacity) {
            totalValue += items[i].value;
            capacity -= items[i].weight;
        } else {
            totalValue += items[i].ratio * capacity;
            capacity = 0;
        }
    }

    return totalValue;
}

int main() {
    int value[] = {60, 100, 120};
    int weight[] = {10, 20, 30};
    int capacity = 50;

    int n = 3;

    printf("%.0f\n", fractionalKnapsack(value, weight, n, capacity));

    return 0;
}