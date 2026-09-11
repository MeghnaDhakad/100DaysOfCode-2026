#include <stdio.h>

struct Job {
    int id;
    int deadline;
    int profit;
};

void sortJobs(struct Job jobs[], int n) {
    // Sort by profit in descending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (jobs[i].profit < jobs[j].profit) {
                struct Job temp = jobs[i];
                jobs[i] = jobs[j];
                jobs[j] = temp;
            }
        }
    }
}

int main() {
    int n;

    scanf("%d", &n);

    struct Job jobs[n];

    for (int i = 0; i < n; i++) {
        jobs[i].id = i + 1;
        scanf("%d %d", &jobs[i].deadline, &jobs[i].profit);
    }

    sortJobs(jobs, n);

    // Find maximum deadline
    int maxDeadline = 0;

    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > maxDeadline)
            maxDeadline = jobs[i].deadline;
    }

    // Slots: 0 means empty
    int slot[maxDeadline + 1];

    for (int i = 0; i <= maxDeadline; i++)
        slot[i] = -1;

    int totalProfit = 0;
    int count = 0;

    // Schedule jobs
    for (int i = 0; i < n; i++) {

        // Find latest free slot before deadline
        for (int j = jobs[i].deadline; j >= 1; j--) {

            if (slot[j] == -1) {
                slot[j] = jobs[i].id;
                totalProfit += jobs[i].profit;
                count++;
                break;
            }
        }
    }

    printf("%d\n", totalProfit);

    return 0;
}
