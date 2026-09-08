#include <stdio.h>
#include <stdlib.h>

struct Activity {
    int start;
    int end;
};

int compare(const void *a, const void *b) {
    struct Activity *x = (struct Activity *)a;
    struct Activity *y = (struct Activity *)b;

    return x->end - y->end;
}

int maxActivities(int n, int start[], int end[]) {
    struct Activity activities[n];

    // Create activity pairs
    for (int i = 0; i < n; i++) {
        activities[i].start = start[i];
        activities[i].end = end[i];
    }

    // Sort activities by ending time
    qsort(activities, n, sizeof(struct Activity), compare);

    int count = 0;
    int lastEnd = -1;

    // Select activities greedily
    for (int i = 0; i < n; i++) {
        if (activities[i].start >= lastEnd) {
            count++;
            lastEnd = activities[i].end;
        }
    }

    return count;
}

int main() {
    int n;

    printf("Enter number of activities: ");
    scanf("%d", &n);

    int start[n], end[n];

    printf("Enter start times: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &start[i]);
    }

    printf("Enter end times: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &end[i]);
    }

    printf("Maximum number of activities: %d\n",
           maxActivities(n, start, end));

    return 0;
}