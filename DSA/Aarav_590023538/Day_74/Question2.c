pp
#include <bits/stdc++.h>
using namespace std;

int N, T;
vector<vector<int>> adj;
vector<bool> covered;
vector<bool> visited;

// Post-order DFS greedy: a node becomes a "head" if it has at least one
// still-uncovered child once its whole subtree has been processed, pairing
// with up to T of those children as its "feet". Otherwise it stays
// uncovered, available to become a foot for its own parent.
void dfs(int u, int parent) {
    visited[u] = true;
    vector<int> availableChildren;

    for (int v : adj[u]) {
        if (v == parent || visited[v]) continue;
        dfs(v, u);
        if (!covered[v]) availableChildren.push_back(v);
    }

    if (!availableChildren.empty()) {
        int k = min((int)availableChildren.size(), T);
        covered[u] = true;
        for (int i = 0; i < k; i++) covered[availableChildren[i]] = true;
    }
}

int main() {
    int C;
    cin >> C;
    while (C--) {
        int n, t, m;
        cin >> n >> t >> m;

        N = n; T = t;
        adj.assign(n + 1, {});
        covered.assign(n + 1, false);
        visited.assign(n + 1, false);

        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        for (int i = 1; i <= n; i++) if (!visited[i]) dfs(i, 0);

        int total = 0;
        for (int i = 1; i <= n; i++) if (covered[i]) total++;
        cout << total << "\n";
    }
    return 0;
}
