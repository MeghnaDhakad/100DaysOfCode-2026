pp
#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& nums) {
    int ones = 0;
    int twos = 0;

    for (int x : nums) {
        ones = (ones ^ x) & ~twos;
        twos = (twos ^ x) & ~ones;
    }

    return ones;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    cout << singleNumber(nums) << "\n";
    return 0;
}
