#include <stdio.h>
#include <stdlib.h>

int compareInt(const void* a, const void* b) { return *(int*)a - *(int*)b; }

int minMeetingRooms(int** intervals, int intervalsSize, int* intervalsColSize) {
    if (intervalsSize == 0) return 0;
    int* starts = (int*)malloc(intervalsSize * sizeof(int));
    int* ends = (int*)malloc(intervalsSize * sizeof(int));
    for (int i = 0; i < intervalsSize; i++) {
        starts[i] = intervals[i][0];
        ends[i] = intervals[i][1];
    }
    qsort(starts, intervalsSize, sizeof(int), compareInt);
    qsort(ends, intervalsSize, sizeof(int), compareInt);
    int rooms = 0, endIdx = 0;
    for (int i = 0; i < intervalsSize; i++) {
        if (starts[i] < ends[endIdx]) rooms++;
        else endIdx++;
    }
    free(starts); free(ends);
    return rooms;
}

int main() {
    int i1[] = {0, 30}, i2[] = {5, 10}, i3[] = {15, 20};
    int* intervals[] = {i1, i2, i3};
    int col = 2;
    printf("%d\n", minMeetingRooms(intervals, 3, &col));
    return 0;
}
