#include <stdio.h>

int timeRequiredToBuy(int tickets[], int n, int k) {

    int time = 0;

    while (tickets[k] > 0) {

        for (int i = 0; i < n; i++) {

            if (tickets[i] > 0) {

                tickets[i]--;
                time++;

                if (i == k && tickets[k] == 0)
                    return time;
            }
        }
    }

    return time;
}

int main() {

    int n, k;

    printf("Enter number of people: ");
    scanf("%d", &n);

    int tickets[n];

    printf("Enter tickets required by each person: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &tickets[i]);

    printf("Enter position k: ");
    scanf("%d", &k);

    printf("Time required: %d\n", timeRequiredToBuy(tickets, n, k));

    return 0;
}