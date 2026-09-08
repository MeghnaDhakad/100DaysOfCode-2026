pp
#include <bits/stdc++.h>
using namespace std;

int findSingleNumber(const vector<int>& nums) {
    int ans = 0;

    for (int x : nums)
        ans ^= x;

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    cout << findSingleNumber(nums) << "\n";
    return 0;
}
