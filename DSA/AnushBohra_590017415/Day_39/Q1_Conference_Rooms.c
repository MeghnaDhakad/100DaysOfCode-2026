#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int minMeetingRooms(int** intervals, int intervalsSize, int* intervalsColSize) {
    if (intervalsSize == 0) return 0;

    int* startTimes = (int*)malloc(intervalsSize * sizeof(int));
    int* endTimes = (int*)malloc(intervalsSize * sizeof(int));

    for (int i = 0; i < intervalsSize; i++) {
        startTimes[i] = intervals[i][0];
        endTimes[i] = intervals[i][1];
    }

    qsort(startTimes, intervalsSize, sizeof(int), compare);
    qsort(endTimes, intervalsSize, sizeof(int), compare);

    int rooms = 0;
    int endPtr = 0;

    for (int startPtr = 0; startPtr < intervalsSize; startPtr++) {
        if (startTimes[startPtr] < endTimes[endPtr]) {
            rooms++;
        } else {
            endPtr++;
        }
    }

    free(startTimes);
    free(endTimes);

    return rooms;
}

int main() {
    int row1[] = {1, 5};
    int row2[] = {2, 6};
    int row3[] = {4, 8};
    int row4[] = {9, 10};

    int* intervals[] = {row1, row2, row3, row4};
    int intervalsSize = 4;
    int intervalsColSize[] = {2, 2, 2, 2};

    int result = minMeetingRooms(intervals, intervalsSize, intervalsColSize);
    printf("Output: %d\n", result);

    return 0;
}