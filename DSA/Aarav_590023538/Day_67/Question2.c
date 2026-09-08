pp
#include <bits/stdc++.h>
using namespace std;

int cntM1 = 0, cnt0 = 0, cntP1 = 0;

// Recursively builds the minimal-height BST over arr[l..r] and returns
// the subtree's height (-1 for an empty subtree), tallying balance
// factors along the way.
int build(vector<int>& arr, int l, int r) {
    if (l > r) return -1; // empty subtree, height -1

    int mid = l + (r - l) / 2; // picks the left-middle element for even-length segments

    int leftH  = build(arr, l, mid - 1);
    int rightH = build(arr, mid + 1, r);

    int bf = rightH - leftH; // balance factor of this node
    if (bf == -1) cntM1++;
    else if (bf == 0) cnt0++;
    else if (bf == 1) cntP1++;

    return max(leftH, rightH) + 1;
}

vector<int> balanceSpectrum(vector<int>& arr) {
    cntM1 = cnt0 = cntP1 = 0;
    build(arr, 0, (int)arr.size() - 1);
    return {cntM1, cnt0, cntP1};
}

int main() {
    vector<int> arr1 = {1, 2, 3, 4, 5, 6, 7};
    auto r1 = balanceSpectrum(arr1); // 0 7 0

    vector<int> arr2 = {42};
    auto r2 = balanceSpectrum(arr2); // 0 1 0

    return 0;
}
