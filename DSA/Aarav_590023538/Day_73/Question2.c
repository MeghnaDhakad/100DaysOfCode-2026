pp
#include <bits/stdc++.h>
using namespace std;

vector<int> complementBFS(int n, int s, vector<unordered_set<int>>& adj) {
    vector<int> dist(n + 1, -1);
    dist[s] = 0;

    set<int> unvisited;
    for (int i = 1; i <= n; i++) if (i != s) unvisited.insert(i);

    queue<int> q;
    q.push(s);

    while (!q.empty()) {
        int u = q.front(); q.pop();

        vector<int> toRemove;
        for (int v : unvisited) {
            if (adj[u].find(v) == adj[u].end()) {
                dist[v] = dist[u] + 1;
                toRemove.push_back(v);
                q.push(v);
            }
        }
        for (int v : toRemove) unvisited.erase(v);
    }
    return dist;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<unordered_set<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    int s;
    cin >> s;

    vector<int> dist = complementBFS(n, s, adj);

    bool first = true;
    for (int i = 1; i <= n; i++) {
        if (i == s) continue;
        if (!first) cout << " ";
        cout << dist[i];
        first = false;
    }
    cout << "\n";
    return 0;
}
