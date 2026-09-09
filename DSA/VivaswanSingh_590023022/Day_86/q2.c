#include <stdlib.h>

typedef struct
{
    int value;
    int weight;
    double ratio;
} Item;

int compare(const void *a, const void *b)
{
    Item *x = (Item *)a;
    Item *y = (Item *)b;

    if (x->ratio < y->ratio)
        return 1;

    if (x->ratio > y->ratio)
        return -1;

    return 0;
}

double fractionalKnapsack(int n, int value[], int weight[], int capacity)
{
    Item items[n];

    for (int i = 0; i < n; i++)
    {
        items[i].value = value[i];
        items[i].weight = weight[i];
        items[i].ratio = (double)value[i] / weight[i];
    }

    qsort(items, n, sizeof(Item), compare);

    double totalValue = 0.0;
    int remaining = capacity;

    for (int i = 0; i < n; i++)
    {
        if (remaining == 0)
            break;

        if (items[i].weight <= remaining)
        {
            totalValue += items[i].value;
            remaining -= items[i].weight;
        }
        else
        {
            totalValue += items[i].ratio * remaining;
            remaining = 0;
        }
    }

    return totalValue;
}