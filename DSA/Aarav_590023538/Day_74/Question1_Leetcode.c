pp
#include <bits/stdc++.h>
using namespace std;

vector<int> parent, sz;

int find(int x) {
    while (parent[x] != x) {
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
    return x;
}

void unite(int a, int b) {
    a = find(a); b = find(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    parent[b] = a;
    sz[a] += sz[b];
}

long long countPairs(int n, vector<vector<int>>& edges) {
    parent.resize(n);
    sz.assign(n, 1);
    iota(parent.begin(), parent.end(), 0);

    for (auto& e : edges) unite(e[0], e[1]);

    long long remaining = n, ans = 0;
    for (int i = 0; i < n; i++) {
        if (find(i) == i) { // representative of a component
            ans += (long long) sz[i] * (remaining - sz[i]);
            remaining -= sz[i];
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> e1 = {{0,1},{0,2},{1,2}};
    cout << countPairs(3, e1) << endl; // 0

    vector<vector<int>> e2 = {{0,2},{0,5},{2,4},{1,6},{5,4}};
    cout << countPairs(7, e2) << endl; // 14

    return 0;
}
