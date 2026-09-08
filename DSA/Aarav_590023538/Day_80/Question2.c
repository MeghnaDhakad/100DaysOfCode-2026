pp
#include <bits/stdc++.h>
using namespace std;

bool isPowerOfTwoOrZero(int n) {
    return n == 0 || (n & (n - 1)) == 0;
}

int main() {
    int n;
    cin >> n;

    cout << (isPowerOfTwoOrZero(n) ? "true" : "false") << "\n";
    return 0;
}
