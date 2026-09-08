pp
#include <bits/stdc++.h>
using namespace std;

bool hasEulerTrail(int n, const vector<pair<int, int>>& edges) {
    vector<int> degree(n + 1, 0);

    for (auto [u, v] : edges) {
        degree[u]++;
        degree[v]++;
    }

    int odd = 0;
    for (int i = 1; i <= n; i++)
        odd += (degree[i] & 1);

    return odd == 0 || odd == 2;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<pair<int, int>> edges(m);
    for (auto& [u, v] : edges)
        cin >> u >> v;

    vector<pair<int, int>> curEdges = edges;
    int curN = n;

    for (int step = 0; step < k; step++) {
        vector<vector<int>> incident(curN + 1);

        for (int i = 0; i < (int)curEdges.size(); i++) {
            auto [u, v] = curEdges[i];
            incident[u].push_back(i);
            incident[v].push_back(i);
        }

        vector<pair<int, int>> nextEdges;

        for (int u = 1; u <= curN; u++) {
            auto& list = incident[u];
            for (int i = 0; i < (int)list.size(); i++) {
                for (int j = i + 1; j < (int)list.size(); j++) {
                    nextEdges.push_back({list[i] + 1, list[j] + 1});
                }
            }
        }

        curN = curEdges.size();
        curEdges.swap(nextEdges);
    }

    cout << (hasEulerTrail(curN, curEdges) ? "true\n" : "false\n");
    return 0;
}
