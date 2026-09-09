#include <stdio.h>
struct Item {
    int value;
    int weight;
    float ratio;
};
int main() {
    int n, capacity;
    printf("Enter number of items: ");
    scanf("%d", &n);
    struct Item item[n];
    printf("Enter values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &item[i].value);
    }
    printf("Enter weights:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &item[i].weight);
        item[i].ratio = (float)item[i].value / item[i].weight;
    }
    printf("Enter capacity: ");
    scanf("%d", &capacity);
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (item[i].ratio < item[j].ratio) {
                struct Item temp = item[i];
                item[i] = item[j];
                item[j] = temp;
            }
        }
    }
    float totalValue = 0;
    for (int i = 0; i < n; i++) {
        if (item[i].weight <= capacity) {
            totalValue += item[i].value;
            capacity -= item[i].weight;
        }
        else {
            totalValue += item[i].ratio * capacity;
            break;
        }
    }
    printf("Maximum value = %.2f\n", totalValue);
    return 0;
}