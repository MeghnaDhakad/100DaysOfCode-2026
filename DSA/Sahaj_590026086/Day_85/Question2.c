#include <stdio.h>
#include <stdlib.h>

typedef struct { int start; int end; } Activity;
int compareActivity(const void* a, const void* b) { return ((Activity*)a)->end - ((Activity*)b)->end; }

int maxActivities(Activity* arr, int n) {
    qsort(arr, n, sizeof(Activity), compareActivity);
    int count = 1, lastEnd = arr[0].end;
    for (int i = 1; i < n; i++) {
        if (arr[i].start >= lastEnd) {
            count++;
            lastEnd = arr[i].end;
        }
    }
    return count;
}

int main() {
    Activity arr[] = {{1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}, {5, 9}};
    printf("%d\n", maxActivities(arr, 6));
    return 0;
}
