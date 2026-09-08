#include <stdio.h>
#include <stdlib.h>

typedef struct { int len; int bty; } Song;
int compareSong(const void* a, const void* b) { return ((Song*)b)->bty - ((Song*)a)->bty; }
int compareInt(const void* a, const void* b) { return *(int*)a - *(int*)b; }

long long maxPleasure(int* length, int* beauty, int n, int k) {
    Song* songs = (Song*)malloc(n * sizeof(Song));
    for (int i = 0; i < n; i++) { songs[i].len = length[i]; songs[i].bty = beauty[i]; }
    qsort(songs, n, sizeof(Song), compareSong);
    int* heap = (int*)malloc(n * sizeof(int));
    int heapSize = 0;
    long long sumLen = 0, best = 0;
    for (int i = 0; i < n; i++) {
        heap[heapSize++] = songs[i].len;
        sumLen += songs[i].len;
        qsort(heap, heapSize, sizeof(int), compareInt);
        if (heapSize > k) { sumLen -= heap[0]; for (int j = 0; j < heapSize - 1; j++) heap[j] = heap[j + 1]; heapSize--; }
        long long curr = sumLen * songs[i].bty;
        if (curr > best) best = curr;
    }
    free(heap); free(songs);
    return best;
}

int main() {
    int len[] = {4, 15, 3, 6}, bty[] = {7, 1, 6, 8};
    printf("%lld\n", maxPleasure(len, bty, 4, 3));
    return 0;
}
