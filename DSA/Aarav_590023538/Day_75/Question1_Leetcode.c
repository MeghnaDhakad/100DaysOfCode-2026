pp
#include <bits/stdc++.h>
using namespace std;

int largestPathValue(string colors, vector<vector<int>>& edges) {
    int n = colors.size();
    vector<vector<int>> adj(n);
    vector<int> indegree(n, 0);
    for (auto& e : edges) {
        adj[e[0]].push_back(e[1]);
        indegree[e[1]]++;
    }

    vector<array<int, 26>> count(n);
    for (auto& row : count) row.fill(0);

    queue<int> q;
    for (int i = 0; i < n; i++) if (indegree[i] == 0) q.push(i);

    int visited = 0, ans = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        visited++;

        int c = colors[u] - 'a';
        count[u][c]++;
        ans = max(ans, count[u][c]);

        for (int v : adj[u]) {
            for (int k = 0; k < 26; k++)
                count[v][k] = max(count[v][k], count[u][k]);
            if (--indegree[v] == 0) q.push(v);
        }
    }

    return visited == n ? ans : -1;
}

int main() {
    string colors;
    cin >> colors;
    int m;
    cin >> m;
    vector<vector<int>> edges(m, vector<int>(2));
    for (int i = 0; i < m; i++) cin >> edges[i][0] >> edges[i][1];
    cout << largestPathValue(colors, edges) << "\n";
    return 0;
}
