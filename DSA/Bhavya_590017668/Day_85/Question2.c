#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Activity;

int compare(const void* a, const void* b) {
    return ((Activity*)a)->end - ((Activity*)b)->end;
}

int maxActivities(Activity activities[], int n) {
    qsort(activities, n, sizeof(Activity), compare);
    int count = 1;
    int lastEnd = activities[0].end;
    for (int i = 1; i < n; i++) {
        if (activities[i].start >= lastEnd) {
            count++;
            lastEnd = activities[i].end;
        }
    }
    return count;
}

int main() {
    Activity activities[] = {{1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}, {5, 9}};
    int n = sizeof(activities) / sizeof(activities[0]);
    printf("%d\n", maxActivities(activities, n));
    return 0;
}