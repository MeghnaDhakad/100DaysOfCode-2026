pp
#include <bits/stdc++.h>
using namespace std;

long long maxPleasure(vector<int>& length, vector<int>& beauty, int k) {
    int n = length.size();
    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);

    // Process songs in decreasing order of beauty
    sort(idx.begin(), idx.end(), [&](int a, int b) {
        return beauty[a] > beauty[b];
    });

    priority_queue<int, vector<int>, greater<int>> minHeap; // smallest length on top
    long long sumLen = 0, best = 0;

    for (int i : idx) {
        int len = length[i];
        int bty = beauty[i];

        minHeap.push(len);
        sumLen += len;

        if ((int)minHeap.size() > k) {
            sumLen -= minHeap.top();
            minHeap.pop();
        }

        // Current song has the smallest beauty among all selected so far
        best = max(best, sumLen * (long long)bty);
    }

    return best;
}

int main() {
    vector<int> len1 = {4, 15, 3, 6};
    vector<int> b1   = {7, 1, 6, 8};
    cout << maxPleasure(len1, b1, 3) << endl; // 78

    vector<int> len2 = {12, 112, 100, 13, 55};
    vector<int> b2   = {31, 4, 100, 55, 50};
    cout << maxPleasure(len2, b2, 3) << endl; // 10000

    return 0;
}
