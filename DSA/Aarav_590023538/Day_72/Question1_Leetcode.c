#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int closestMeetingNode(int *edges, int n, int node1, int node2) {
    int *dist1 = malloc(sizeof(int) * n);
    int *dist2 = malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        dist1[i] = -1;
        dist2[i] = -1;
    }

    // Walk from node1
    int cur = node1, d = 0;
    while (cur != -1 && dist1[cur] == -1) {
        dist1[cur] = d++;
        cur = edges[cur];
    }

    // Walk from node2
    cur = node2, d = 0;
    while (cur != -1 && dist2[cur] == -1) {
        dist2[cur] = d++;
        cur = edges[cur];
    }

    int best = -1;
    long long bestMax = LLONG_MAX;

    for (int i = 0; i < n; i++) {
        if (dist1[i] == -1 || dist2[i] == -1) continue;
        long long m = dist1[i] > dist2[i] ? dist1[i] : dist2[i];
        if (m < bestMax) {
            bestMax = m;
            best = i;
        }
    }

    free(dist1);
    free(dist2);
    return best;
}

int main(void) {
    int edges[] = {2, 2, 3, -1};
    int n = 4;
    printf("%d\n", closestMeetingNode(edges, n, 0, 1)); // 2

    int edges2[] = {1, 2, -1};
    printf("%d\n", closestMeetingNode(edges2, 3, 0, 2)); // 2

    return 0;
}
