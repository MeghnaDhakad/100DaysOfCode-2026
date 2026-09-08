pp
#include <bits/stdc++.h>
using namespace std;

int numberOfSteps(int num) {
    int steps = 0;

    while (num != 0) {
        if (num & 1)
            num--;
        else
            num >>= 1;

        steps++;
    }

    return steps;
}

int main() {
    int num;
    cin >> num;

    cout << numberOfSteps(num) << "\n";
    return 0;
}
