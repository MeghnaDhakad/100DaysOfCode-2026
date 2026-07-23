#include <stdio.h>

int timeRequiredToBuy(int tickets[], int n, int k) {
    int time = 0;
    int target = tickets[k];

    for (int i = 0; i < n; i++) {
        if (i <= k) {

            if (tickets[i] < target)
                time += tickets[i];
            else
                time += target;
        } else {

            if (tickets[i] < target - 1)
                time += tickets[i];
            else
                time += target - 1;
        }
    }

    return time;
}

int main() {
    int n, k;

    printf("Enter number of people: ");
    scanf("%d", &n);

    int tickets[n];

    printf("Enter tickets required by each person:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &tickets[i]);
    }

    printf("Enter position k: ");
    scanf("%d", &k);

    int result = timeRequiredToBuy(tickets, n, k);

    printf("Time required: %d seconds\n", result);

    return 0;
}