pp
#include <bits/stdc++.h>
using namespace std;

vector<int> bfsDist(int start, vector<int>& edges) {
    int n = edges.size();
    vector<int> dist(n, -1);
    dist[start] = 0;
    int cur = start;
    while (edges[cur] != -1 && dist[edges[cur]] == -1) {
        dist[edges[cur]] = dist[cur] + 1;
        cur = edges[cur];
    }
    return dist;
}

int closestMeetingNode(vector<int>& edges, int node1, int node2) {
    vector<int> dist1 = bfsDist(node1, edges);
    vector<int> dist2 = bfsDist(node2, edges);

    int n = edges.size();
    int best = -1, bestDist = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (dist1[i] == -1 || dist2[i] == -1) continue;
        int d = max(dist1[i], dist2[i]);
        if (d < bestDist) {
            bestDist = d;
            best = i;
        }
    }
    return best;
}

int main() {
    int n;
    cin >> n;
    vector<int> edges(n);
    for (int i = 0; i < n; i++) cin >> edges[i];
    int node1, node2;
    cin >> node1 >> node2;
    cout << closestMeetingNode(edges, node1, node2) << "\n";
    return 0;
}
