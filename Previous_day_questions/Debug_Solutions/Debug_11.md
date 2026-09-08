<h2 align="center">Week 11 Day 7 (30/08/2026) — Weekly Debug 11</h2>

## 1. The Nether Portal Network

### Solution

### Bugs Identified

1. **The edge comparator sorted the edges in descending order.**
   Kruskal's algorithm must consider edges from the smallest weight to the largest weight.
   The buggy comparator returned `((Edge *)b)->w - ((Edge *)a)->w`.
   **Fix:** Return `((Edge *)a)->w - ((Edge *)b)->w`.

2. **The last portal was never initialized.**
   The initialization loop used `i < n`, so `parent[n]` remained uninitialized.
   **Fix:** Change the loop condition to `i <= n`.

3. **The MST completion condition was incorrect.**
   A spanning tree containing `n` portals always has exactly `n - 1` edges. The code incorrectly checked `taken > n - 1`.
   **Fix:** Check `taken == n - 1`.

4. **The algorithm did not stop after selecting `n - 1` edges.**
   Once the required number of edges has been selected, the network is complete and remaining edges do not need to be processed.
   **Fix:** Break the loop when `taken == n - 1`.

### Fixed Code

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, w;
} Edge;

int cmp(const void *a, const void *b) {
    // BUG: return ((Edge *)b)->w - ((Edge *)a)->w;
    return ((Edge *)a)->w - ((Edge *)b)->w;
}

int find(int parent[], int x) {
    while (parent[x] != x)
        x = parent[x];
    return x;
}

void unite(int parent[], int rank[], int x, int y) {
    int rx = find(parent, x);
    int ry = find(parent, y);
    if (rx == ry) return;
    if (rank[rx] < rank[ry])
        parent[rx] = ry;
    else if (rank[rx] > rank[ry])
        parent[ry] = rx;
    else {
        parent[ry] = rx;
        rank[rx]++;
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    Edge *edges = malloc(m * sizeof(Edge));
    for (int i = 0; i < m; i++)
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);

    qsort(edges, m, sizeof(Edge), cmp);

    int *parent = malloc((n + 1) * sizeof(int));
    int *rank = calloc((n + 1), sizeof(int));

    // BUG: for (int i = 1; i < n; i++)
    for (int i = 1; i <= n; i++)
        parent[i] = i;

    long long total = 0;
    int taken = 0;

    for (int i = 0; i < m; i++) {
        if (find(parent, edges[i].u) != find(parent, edges[i].v)) {
            unite(parent, rank, edges[i].u, edges[i].v);
            total += edges[i].w;
            taken++;

            if (taken == n - 1)
                break;
        }
    }

    // BUG: if (taken > n - 1)
    if (taken == n - 1)
        printf("%lld\n", total);
    else
        printf("-1\n");

    free(edges);
    free(parent);
    free(rank);
    return 0;
}
```

### Output

```
10
18
-1
```

### Explanation

- **Sorting:** Kruskal's algorithm processes the cheapest portal links first so that the total Obsidian cost is minimized.
- **DSU:** `find()` identifies the group containing a portal, while `unite()` merges two separate groups.
- **Cycle Prevention:** A link is added only when its two portals belong to different groups.
- **MST Completion:** A connected network of `n` portals contains exactly `n - 1` selected links.
- **Disconnected Network:** If fewer than `n - 1` links can be selected, all portals cannot be connected, so the program prints `-1`.

### Complexity

- **Time Complexity:** `O(m log m)` due to `qsort()`, with DSU operations adding near-linear `O(m α(n))`.
- **Space Complexity:** `O(n + m)` for the edge array and DSU arrays.
- **Inbuilt Function:** `qsort()` from `<stdlib.h>` is the standard C library function used for sorting. C does not provide a built-in Minimum Spanning Tree function, so Kruskal's algorithm must be implemented.
