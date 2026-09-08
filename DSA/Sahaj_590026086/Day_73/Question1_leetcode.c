#include <stdio.h>
#include <stdlib.h>

void bfsDist(int* edges, int n, int start, int* dist) {
    for (int i = 0; i < n; i++) dist[i] = -1;
    int d = 0, curr = start;
    while (curr != -1 && dist[curr] == -1) {
        dist[curr] = d++;
        curr = edges[curr];
    }
}

int closestMeetingNode(int* edges, int edgesSize, int node1, int node2) {
    int* d1 = (int*)malloc(edgesSize * sizeof(int));
    int* d2 = (int*)malloc(edgesSize * sizeof(int));
    bfsDist(edges, edgesSize, node1, d1);
    bfsDist(edges, edgesSize, node2, d2);
    int minMaxDist = 1e9, ans = -1;
    for (int i = 0; i < edgesSize; i++) {
        if (d1[i] != -1 && d2[i] != -1) {
            int maxD = d1[i] > d2[i] ? d1[i] : d2[i];
            if (maxD < minMaxDist) { minMaxDist = maxD; ans = i; }
        }
    }
    free(d1); free(d2);
    return ans;
}

int main() {
    int edges[] = {1, 2, -1};
    printf("%d\n", closestMeetingNode(edges, 3, 0, 1));
    return 0;
}
