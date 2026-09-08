pp
#include <bits/stdc++.h>
using namespace std;

bool canMakeArithmeticProgression(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    int diff = arr[1] - arr[0];
    for (int i = 2; i < arr.size(); i++) {
        if (arr[i] - arr[i - 1] != diff) return false;
    }
    return true;
}

int main() {
    vector<int> arr1 = {3, 5, 1};
    cout << (canMakeArithmeticProgression(arr1) ? "true" : "false") << endl; // true

    vector<int> arr2 = {1, 2, 4};
    cout << (canMakeArithmeticProgression(arr2) ? "true" : "false") << endl; // false

    return 0;
}
