#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int deadline;
    int profit;
} Job;

int compare(const void *a, const void *b) {
    Job *x = (Job *)a;
    Job *y = (Job *)b;

    return y->profit - x->profit;
}

int jobSequencing(int deadline[], int profit[], int n) {
    Job jobs[n];

    int maxDeadline = 0;

    for (int i = 0; i < n; i++) {
        jobs[i].deadline = deadline[i];
        jobs[i].profit = profit[i];

        if (deadline[i] > maxDeadline)
            maxDeadline = deadline[i];
    }

    qsort(jobs, n, sizeof(Job), compare);

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
    int deadline[] = {4, 1, 1, 1};
    int profit[] = {20, 10, 40, 30};

    int n = 4;

    printf("%d\n", jobSequencing(deadline, profit, n));

    return 0;
}