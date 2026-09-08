#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int findContentChildren(int g[], int gSize, int s[], int sSize) {
    qsort(g, gSize, sizeof(int), compare);
    qsort(s, sSize, sizeof(int), compare);

    int child = 0;
    int cookie = 0;

    while (child < gSize && cookie < sSize) {
        if (s[cookie] >= g[child]) {
            child++;
        }

        cookie++;
    }

    return child;
}

int main() {
    int gSize, sSize;

    printf("Enter number of children: ");
    scanf("%d", &gSize);

    int g[gSize];

    printf("Enter greed factors: ");
    for (int i = 0; i < gSize; i++) {
        scanf("%d", &g[i]);
    }

    printf("Enter number of cookies: ");
    scanf("%d", &sSize);

    int s[sSize];

    if (sSize > 0) {
        printf("Enter cookie sizes: ");
        for (int i = 0; i < sSize; i++) {
            scanf("%d", &s[i]);
        }
    }

    printf("Maximum content children: %d\n",
           findContentChildren(g, gSize, s, sSize));

    return 0;
}