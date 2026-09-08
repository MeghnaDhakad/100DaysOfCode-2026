pp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    // adj[u] holds the (at most 2) roads touching u, each stored as
    // {neighbor, sign, cost} where sign = +1 if the road is given as u->v,
    // and sign = -1 if the road is given as v->u.
    vector<vector<array<int, 3>>> adj(n + 1);
    long long totalCost = 0;

    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, 1, c});
        adj[b].push_back({a, -1, c});
        totalCost += c;
    }

    int cur = 1, prev = -1;
    long long costClockwise = 0; // cost to orient every road along the traversal 1 -> ... -> 1

    for (int step = 0; step < n; step++) {
        for (auto& road : adj[cur]) {
            int v = road[0], sign = road[1], cost = road[2];
            if (v == prev) continue;
            if (sign == -1) costClockwise += cost; // road currently points against the traversal
            prev = cur;
            cur = v;
            break;
        }
    }

    cout << min(costClockwise, totalCost - costClockwise) << "\n";
    return 0;
}
