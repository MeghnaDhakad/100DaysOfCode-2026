#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int minMeetingRooms(int intervals[][2], int n) {
    int *start = (int *)malloc(n * sizeof(int));
    int *end = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        start[i] = intervals[i][0];
        end[i] = intervals[i][1];
    }

    qsort(start, n, sizeof(int), compare);
    qsort(end, n, sizeof(int), compare);

    int i = 0;
    int j = 0;
    int rooms = 0;
    int maxRooms = 0;

    while (i < n) {

        if (start[i] < end[j]) {
            rooms++;
            i++;

            if (rooms > maxRooms)
                maxRooms = rooms;
        } 
        else {

            rooms--;
            j++;
        }
    }

    free(start);
    free(end);

    return maxRooms;
}

int main() {
    int n;

    printf("Enter number of meetings: ");
    scanf("%d", &n);

    int intervals[n][2];

    printf("Enter start and end time for each meeting:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &intervals[i][0], &intervals[i][1]);
    }

    int result = minMeetingRooms(intervals, n);

    printf("Minimum conference rooms required: %d\n", result);

    return 0;
}