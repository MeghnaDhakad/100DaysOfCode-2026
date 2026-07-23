#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    int *x = *(int **)a;
    int *y = *(int **)b;
    return x[0] - y[0];
}

int minMeetingRooms(int **intervals, int intervalsSize) {
    if (intervalsSize == 0)
        return 0;
    qsort(intervals, intervalsSize, sizeof(int *), compare);
    int queue[1000];
    int top = 0, bottom = -1;
    int rooms = 0;

    for(int i = 0; i < intervalsSize; i++){
        while(top <= bottom && queue[top] <= intervals[i][0])
            top++;
        queue[++bottom] = intervals[i][1];
        if(bottom - top + 1 > rooms)
            rooms = bottom - top + 1;
    }
    return rooms;
}

int main() {
    int n;
    printf("Enter number of meetings: ");
    scanf("%d", &n);
    int **intervals = (int **)malloc(n * sizeof(int *));

    for (int i = 0; i < n; i++)
        intervals[i] = (int *)malloc(2 * sizeof(int));

    printf("Enter start and end time of each meeting:\n");
    for (int i = 0; i < n; i++)
        scanf("%d %d", &intervals[i][0], &intervals[i][1]);
    printf("Minimum Meeting Rooms Required = %d\n",
           minMeetingRooms(intervals, n));
    for (int i = 0; i < n; i++)
        free(intervals[i]);
    free(intervals);
    return 0;
}