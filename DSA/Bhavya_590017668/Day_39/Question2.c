#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int minMeetingRooms(int** intervals, int intervalsSize, int* intervalsColSize) {
    if (intervalsSize == 0)
        return 0;

    int *start = (int *)malloc(intervalsSize * sizeof(int));
    int *end = (int *)malloc(intervalsSize * sizeof(int));

    for (int i = 0; i < intervalsSize; i++) {
        start[i] = intervals[i][0];
        end[i] = intervals[i][1];
    }

    qsort(start, intervalsSize, sizeof(int), cmp);
    qsort(end, intervalsSize, sizeof(int), cmp);

    int rooms = 0, maxRooms = 0;
    int i = 0, j = 0;

    while (i < intervalsSize) {
        if (start[i] < end[j]) {
            rooms++;
            if (rooms > maxRooms)
                maxRooms = rooms;
            i++;
        } else {
            rooms--;
            j++;
        }
    }

    free(start);
    free(end);

    return maxRooms;
}