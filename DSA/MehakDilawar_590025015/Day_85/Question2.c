//Write an efficient function to select the maximum number of non-overlapping activities for a single person, 
//where each activity has a start time and an end time. Solve the problem using a greedy algorithm.
//Input: n = 6, start = [1, 3, 0, 5, 8, 5], end = [2, 4, 6, 7, 9, 9]. Output: 4.
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Activity;

int compare(const void *a, const void *b) {
    Activity *x = (Activity *)a;
    Activity *y = (Activity *)b;
    return x->end - y->end;
}

int maxActivities(Activity activities[], int n) {
    qsort(activities, n, sizeof(Activity), compare);
    int count = 0;
    int lastEnd = -1;
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
    Activity activities[n];
    printf("Enter start times:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &activities[i].start);
    }
    printf("Enter end times:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &activities[i].end);
    }
    int result = maxActivities(activities, n);
    printf("Maximum number of non-overlapping activities: %d\n", result);
return 0;
}
