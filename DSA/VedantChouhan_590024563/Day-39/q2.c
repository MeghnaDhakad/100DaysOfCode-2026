#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int minMeetingRooms(int intervals[][2], int n) {

    int start[n], end[n];

    for (int i = 0; i < n; i++) {
        start[i] = intervals[i][0];
        end[i] = intervals[i][1];
    }

    qsort(start, n, sizeof(int), compare);
    qsort(end, n, sizeof(int), compare);

    int rooms = 0, maxRooms = 0;
    int i = 0, j = 0;

    while (i < n) {

        if (start[i] < end[j]) {
            rooms++;
            if (rooms > maxRooms)
                maxRooms = rooms;
            i++;
        }
        else {
            rooms--;
            j++;
        }
    }

    return maxRooms;
}

int main() {

    int n;

    printf("Enter number of meetings: ");
    scanf("%d", &n);

    int intervals[n][2];

    printf("Enter start and end times:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &intervals[i][0], &intervals[i][1]);
    }

    printf("Minimum rooms required: %d\n", minMeetingRooms(intervals, n));

    return 0;
}