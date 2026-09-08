pp
#include <bits/stdc++.h>
using namespace std;

string favouriteNumber(vector<int>& nums, int favoriteIndex, int k) {
    int val = nums[favoriteIndex - 1]; // convert to 0-indexed
    int cntGreater = 0, cntEqual = 0;

    for (int x : nums) {
        if (x > val) cntGreater++;
        else if (x == val) cntEqual++;
    }

    if (cntGreater + cntEqual <= k) return "YES";   // definitely removed
    if (cntGreater >= k) return "NO";                // definitely not removed
    return "MAYBE";                                  // depends on tie-breaking
}

int main() {
    vector<int> nums1 = {4, 3, 3, 2, 3};
    cout << favouriteNumber(nums1, 2, 2) << endl; // MAYBE

    vector<int> nums2 = {4, 2, 1, 3, 5};
    cout << favouriteNumber(nums2, 5, 3) << endl; // YES

    vector<int> nums3 = {5, 2, 4, 1, 3};
    cout << favouriteNumber(nums3, 5, 2) << endl; // NO

    return 0;
}
