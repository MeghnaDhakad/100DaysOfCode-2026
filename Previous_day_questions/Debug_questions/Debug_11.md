<h2 align="center">Week 11 Day 7 (30/08/2026) — Weekly Debug 11</h2>

## 1. The Nether Portal Network

The Ghasts are attacking, and the Overworld's portal network is in chaos!

Steve needs to connect all the Nether Portals using Obsidian pathways. Each portal is a node, and every possible connection between two portals has an Obsidian cost. Your mission is to build the network using the minimum possible Obsidian while ensuring that every portal can reach every other portal.

The code below is supposed to construct this network using Kruskal's algorithm and Disjoint Set Union (DSU).

However, something has gone terribly wrong.

The code compiles and runs, but the portal network is unreliable. Some connections are unnecessarily expensive, some portals behave unpredictably, and the final result is sometimes completely wrong.

The bugs are hidden in plain sight.

Your Task: Find and fix all 4 bugs before the Ghasts destroy the network.

### What the Code Must Do

- Read the number of portals and possible portal links.
- Read each link containing two portals and the Obsidian cost.
- Consider cheaper links before expensive ones.
- Remember which portals are already connected to avoid cycles.
- Add a link only when it connects two previously separate groups.
- Stop once all portals belong to a single connected network.
- Calculate the minimum total Obsidian required to connect every portal.
- Print -1 if it is impossible to connect all portals.

### Constraints

- Do not add any new functions.
- Fix all syntax, logical, and runtime errors.
- The code contains exactly 4 bugs.
- Some bugs may cause incorrect output without causing compilation errors.
- Do not redesign the program or use additional data structures.
- The output must match exactly.

### Examples

**Input:**
```
4 5
1 2 10
1 3 5
2 3 3
2 4 7
3 4 2
```

**Output:**
```
10
```

**Input:**
```
4 3
1 2 5
2 3 6
3 4 7
```

**Output:**
```
18
```

**Input:**
```
5 3
1 2 4
2 3 5
4 5 6
```

**Output:**
```
-1
```

### Buggy Code

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, w;
} Edge;

int cmp(const void *a, const void *b) {
    return ((Edge *)b)->w - ((Edge *)a)->w;
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

    for (int i = 1; i < n; i++)
        parent[i] = i;

    long long total = 0;
    int taken = 0;

    for (int i = 0; i < m; i++) {
        if (find(parent, edges[i].u) != find(parent, edges[i].v)) {
            unite(parent, rank, edges[i].u, edges[i].v);
            total += edges[i].w;
            taken++;
        }
    }

    if (taken > n - 1)
        printf("%lld\n", total);
    else
        printf("-1\n");

    free(edges);
    free(parent);
    free(rank);
    return 0;
}
```
