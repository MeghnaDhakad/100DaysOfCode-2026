#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 100005

int N, M, S;
int dist_[MAXN];

// doubly linked list over unvisited vertices (1..N), 0 = head sentinel
int nxt[MAXN + 1], prv[MAXN + 1];

// adjacency (main roads) stored as sorted arrays for binary search
int *adj[MAXN];
int adjLen[MAXN];
int edgeU[MAXN], edgeV[MAXN];

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int isMainRoad(int u, int v) {
    int lo = 0, hi = adjLen[u] - 1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (adj[u][mid] == v) return 1;
        if (adj[u][mid] < v) lo = mid + 1;
        else hi = mid - 1;
    }
    return 0;
}

void unlinkNode(int v) {
    nxt[prv[v]] = nxt[v];
    prv[nxt[v]] = prv[v];
}

int queue_[MAXN], qHead, qTail;

void solve(void) {
    scanf("%d %d", &N, &M);

    int *deg = calloc(N + 1, sizeof(int));
    for (int i = 0; i < M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        edgeU[i] = u; edgeV[i] = v;
        deg[u]++; deg[v]++;
    }
    for (int i = 1; i <= N; i++) {
        adj[i] = malloc(sizeof(int) * deg[i]);
        adjLen[i] = 0;
    }
    for (int i = 0; i < M; i++) {
        int u = edgeU[i], v = edgeV[i];
        adj[u][adjLen[u]++] = v;
        adj[v][adjLen[v]++] = u;
    }
    for (int i = 1; i <= N; i++) {
        qsort(adj[i], adjLen[i], sizeof(int), cmp);
    }
    free(deg);

    scanf("%d", &S);

    // build unvisited doubly linked list: 0 <-> 1 <-> 2 <-> ... <-> N <-> 0 (using N+1 as tail sentinel)
    for (int i = 1; i <= N; i++) {
        nxt[i] = i + 1;
        prv[i] = i - 1;
        dist_[i] = -1;
    }
    nxt[0] = 1;
    prv[N + 1] = N;
    nxt[N] = N + 1;
    prv[1] = 0;

    unlinkNode(S);
    dist_[S] = 0;
    qHead = qTail = 0;
    queue_[qTail++] = S;

    while (qHead < qTail) {
        int u = queue_[qHead++];
        int v = nxt[0]; // start scanning unvisited list from the head
        while (v != N + 1) {
            int nextV = nxt[v]; // save before possible unlink
            if (!isMainRoad(u, v)) {
                unlinkNode(v);
                dist_[v] = dist_[u] + 1;
                queue_[qTail++] = v;
            }
            v = nextV;
        }
    }

    // output distances for all nodes except S, ascending vertex order
    int first = 1;
    for (int i = 1; i <= N; i++) {
        if (i == S) continue;
        if (!first) printf(" ");
        printf("%d", dist_[i]);
        first = 0;
    }
    printf("\n");

    for (int i = 1; i <= N; i++) free(adj[i]);
}

int main(void) {
    int T;
    scanf("%d", &T);
    while (T--) {
        solve();
    }
    return 0;
}
