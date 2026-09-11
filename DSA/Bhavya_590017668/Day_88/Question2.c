#include <stdio.h>
#include <stdlib.h>

struct Job {
    int deadline;
    int profit;
};

int compare(const void* a, const void* b) {
    return ((struct Job*)b)->profit - ((struct Job*)a)->profit;
}

int jobSequencing(struct Job jobs[], int n) {
    qsort(jobs, n, sizeof(struct Job), compare);

    int maxDeadline = 0;
    for (int i = 0; i < n; i++)
        if (jobs[i].deadline > maxDeadline)
            maxDeadline = jobs[i].deadline;

    int slot[maxDeadline + 1];
    for (int i = 0; i <= maxDeadline; i++)
        slot[i] = -1;

    int totalProfit = 0;

    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline; j >= 1; j--) {
            if (slot[j] == -1) {
                slot[j] = i;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    return totalProfit;
}

int main() {
    struct Job jobs[] = {
        {2, 100},
        {1, 19},
        {2, 27},
        {1, 25},
        {3, 15}
    };

    int n = sizeof(jobs) / sizeof(jobs[0]);

    printf("%d", jobSequencing(jobs, n));

    return 0;
}