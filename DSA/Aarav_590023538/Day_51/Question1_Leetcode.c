pp
#include <bits/stdc++.h>
using namespace std;

int mostFrequentEven(vector<int>& nums) {
    unordered_map<int, int> freq;
    for (int x : nums) {
        if (x % 2 == 0) freq[x]++;
    }

    int best = -1, bestCount = 0;
    for (auto& [val, cnt] : freq) {
        if (cnt > bestCount || (cnt == bestCount && val < best)) {
            best = val;
            bestCount = cnt;
        }
    }
    return best;
}

int main() {
    vector<int> n1 = {0,1,2,2,4,4,1};
    cout << mostFrequentEven(n1) << endl; // 2

    vector<int> n2 = {4,4,4,9,2,4};
    cout << mostFrequentEven(n2) << endl; // 4

    vector<int> n3 = {29,47,21,41,13,37,25,7};
    cout << mostFrequentEven(n3) << endl; // -1

    return 0;
}
