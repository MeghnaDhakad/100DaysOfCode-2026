pp
#include <bits/stdc++.h>
using namespace std;

int findJudge(int n, vector<pair<int,int>>& trust) {
    vector<int> score(n + 1, 0);
    for (auto& [a, b] : trust) {
        score[a]--;
        score[b]++;
    }
    for (int i = 1; i <= n; i++) {
        if (score[i] == n - 1) return i;
    }
    return -1;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> trust(m);
    for (int i = 0; i < m; i++) {
        cin >> trust[i].first >> trust[i].second;
    }
    cout << findJudge(n, trust) << "\n";
    return 0;
}
