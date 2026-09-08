#include <stdio.h>
#include <stdlib.h>

typedef struct { long long value; long long weight; double ratio; } Item;

int compareItem(const void* a, const void* b) {
    double r1 = ((Item*)a)->ratio;
    double r2 = ((Item*)b)->ratio;
    if (r2 > r1) return 1;
    if (r2 < r1) return -1;
    return 0;
}

double fractionalKnapsack(long long* value, long long* weight, int n, long long capacity) {
    Item* items = (Item*)malloc(n * sizeof(Item));
    for (int i = 0; i < n; i++) {
        items[i].value = value[i];
        items[i].weight = weight[i];
        items[i].ratio = (double)value[i] / weight[i];
    }
    qsort(items, n, sizeof(Item), compareItem);
    double totalValue = 0.0;
    long long remaining = capacity;
    for (int i = 0; i < n; i++) {
        if (remaining == 0) break;
        if (items[i].weight <= remaining) {
            totalValue += items[i].value;
            remaining -= items[i].weight;
        } else {
            totalValue += items[i].ratio * remaining;
            remaining = 0;
        }
    }
    free(items);
    return totalValue;
}

int main() {
    long long val[] = {60, 100, 120};
    long long wt[] = {10, 20, 30};
    printf("%.2f\n", fractionalKnapsack(val, wt, 3, 50));
    return 0;
}
