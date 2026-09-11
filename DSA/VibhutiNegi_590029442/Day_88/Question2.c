#include <stdio.h>
#include <stdlib.h>
struct Job {
    int deadline;
    int profit;
};
int compare(const void *a, const void *b) {
    struct Job *job1 = (struct Job *)a;
    struct Job *job2 = (struct Job *)b;
    return job2->profit - job1->profit;
}
int main() {
    int n;
    printf("Enter number of jobs: ");
    scanf("%d", &n);
    struct Job jobs[n];
    printf("Enter deadlines:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &jobs[i].deadline);
    }
    printf("Enter profits:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &jobs[i].profit);
    }
    qsort(jobs, n, sizeof(struct Job), compare);
    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > maxDeadline) {
            maxDeadline = jobs[i].deadline;
        }
    }
    int slot[maxDeadline + 1];
    for (int i = 0; i <= maxDeadline; i++) {
        slot[i] = 0;
    }
    int totalProfit = 0;
    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline; j >= 1; j--) {
            if (slot[j] == 0) {
                slot[j] = 1;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }
    printf("Maximum Profit = %d\n", totalProfit);
    return 0;
}