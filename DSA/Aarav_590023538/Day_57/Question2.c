pp
#include <bits/stdc++.h>
using namespace std;

bool isMirror(const vector<long long>& a, const vector<long long>& b,
              int i, int j) {
    // If both nodes are missing
    if ((i >= a.size() || a[i] == -1) &&
        (j >= b.size() || b[j] == -1)) {
        return true;
    }

    // If one node is missing
    if (i >= a.size() || a[i] == -1 ||
        j >= b.size() || b[j] == -1) {
        return false;
    }

    // Values must be equal
    if (a[i] != b[j])
        return false;

    // Mirror comparison:
    // left of A <-> right of B
    // right of A <-> left of B
    return isMirror(a, b, 2 * i + 1, 2 * j + 2) &&
           isMirror(a, b, 2 * i + 2, 2 * j + 1);
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n1;
        cin >> n1;

        vector<long long> warehouse1(n1);
        for (int i = 0; i < n1; i++)
            cin >> warehouse1[i];

        int n2;
        cin >> n2;

        vector<long long> warehouse2(n2);
        for (int i = 0; i < n2; i++)
            cin >> warehouse2[i];

        if (isMirror(warehouse1, warehouse2, 0, 0))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
