#include <stdio.h>
int timeRequiredToBuy(int tickets[], int n, int k) {
    int time = 0;

    for (int i = 0; i < n; i++) {
        if (i <= k) {
            time += (tickets[i] < tickets[k]) ? tickets[i] : tickets[k];
        } else {
            time += (tickets[i] < tickets[k] - 1) ? tickets[i] : (tickets[k] - 1);
        }
    }

    return time;
}

int main() {
    int n, k;

    printf("Enter number of people: ");
    scanf("%d", &n);

    int tickets[100];

    printf("Enter tickets required by each person:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &tickets[i]);
    }

    printf("Enter the value of k: ");
    scanf("%d", &k);

    printf("Time required: %d\n", timeRequiredToBuy(tickets, n, k));
    return 0;
}