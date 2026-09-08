pp
#include <bits/stdc++.h>
using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int child = 0;
    int cookie = 0;

    while (child < g.size() && cookie < s.size()) {
        if (s[cookie] >= g[child])
            child++;

        cookie++;
    }

    return child;
}

int main() {
    int n, m;
    cin >> n;

    vector<int> g(n);
    for (int i = 0; i < n; i++)
        cin >> g[i];

    cin >> m;
    vector<int> s(m);
    for (int i = 0; i < m; i++)
        cin >> s[i];

    cout << findContentChildren(g, s) << "\n";
    return 0;
}
