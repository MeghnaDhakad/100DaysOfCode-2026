pp
#include <bits/stdc++.h>
using namespace std;

int countSetBits(int n) {
    int count = 0;

    while (n != 0) {
        n &= (n - 1);
        count++;
    }

    return count;
}

int main() {
    int n;
    cin >> n;

    cout << countSetBits(n) << "\n";
    return 0;
}
