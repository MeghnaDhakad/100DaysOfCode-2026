pp
#include <bits/stdc++.h>
using namespace std;

vector<int> maxSubsequence(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);

    // Stable sort indices by value descending (ties keep original order)
    stable_sort(idx.begin(), idx.end(), [&](int a, int b) {
        return nums[a] > nums[b];
    });

    vector<int> chosen(idx.begin(), idx.begin() + k);
    sort(chosen.begin(), chosen.end()); // restore original relative order

    vector<int> result;
    for (int i : chosen) result.push_back(nums[i]);
    return result;
}

void printVec(const vector<int>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i] << (i + 1 == v.size() ? "" : ",");
    }
    cout << "]\n";
}

int main() {
    vector<int> n1 = {2,1,3,3};
    printVec(maxSubsequence(n1, 2)); // [3,3]

    vector<int> n2 = {-1,-2,3,4};
    printVec(maxSubsequence(n2, 3)); // [-1,3,4]

    vector<int> n3 = {3,4,3,3};
    printVec(maxSubsequence(n3, 2)); // [3,4]

    return 0;
}
