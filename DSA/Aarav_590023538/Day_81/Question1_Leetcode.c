pp
#include <bits/stdc++.h>
using namespace std;

int hammingDistance(int x, int y) {
    unsigned int diff = x ^ y;
    int count = 0;

    while (diff != 0) {
        diff &= (diff - 1);
        count++;
    }

    return count;
}

int main() {
    int x, y;
    cin >> x >> y;

    cout << hammingDistance(x, y) << "\n";
    return 0;
}
