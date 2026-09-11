#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int deadline;
    int profit;
} Job;

int compare(const void *a, const void *b) {
    Job *job1 = (Job *)a;
    Job *job2 = (Job *)b;

    return job2->profit - job1->profit;
}

int main() {
    int deadline[] = {4, 1, 1, 1};
    int profit[] = {20, 10, 40, 30};

    int n = sizeof(deadline) / sizeof(deadline[0]);

    Job jobs[n];

\    for (int i = 0; i < n; i++) {
        jobs[i].deadline = deadline[i];
        jobs[i].profit = profit[i];
    }

\    qsort(jobs, n, sizeof(Job), compare);

\    int maxDeadline = 0;

    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > maxDeadline)
            maxDeadline = jobs[i].deadline;
    }

\    int slot[maxDeadline + 1];

    for (int i = 0; i <= maxDeadline; i++)
        slot[i] = 0;

    int totalProfit = 0;
    int jobsDone = 0;

\    for (int i = 0; i < n; i++) {

\        for (int j = jobs[i].deadline; j >= 1; j--) {

            if (slot[j] == 0) {
                slot[j] = 1;
                totalProfit += jobs[i].profit;
                jobsDone++;
                break;
            }
        }
    }

    printf("Maximum Profit = %d\n", totalProfit);
    printf("Jobs Completed = %d\n", jobsDone);

    return 0;
}