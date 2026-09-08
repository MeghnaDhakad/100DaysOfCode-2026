#include <stdio.h>
#include <stdlib.h>

int compareInt(const void* a, const void* b) { return *(int*)a - *(int*)b; }

int findContentChildren(int* g, int gSize, int* s, int sSize) {
    qsort(g, gSize, sizeof(int), compareInt);
    qsort(s, sSize, sizeof(int), compareInt);
    int i = 0, j = 0;
    while (i < gSize && j < sSize) {
        if (s[j] >= g[i]) i++;
        j++;
    }
    return i;
}

int main() {
    int g[] = {1, 2, 3}, s[] = {1, 1};
    printf("%d\n", findContentChildren(g, 3, s, 2));
    return 0;
}
