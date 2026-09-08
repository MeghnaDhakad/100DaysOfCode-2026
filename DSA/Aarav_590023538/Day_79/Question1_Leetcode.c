pp
#include <bits/stdc++.h>
using namespace std;

string addBinary(string a, string b) {
    int i = (int)a.size() - 1;
    int j = (int)b.size() - 1;
    int carry = 0;

    string ans;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;

        if (i >= 0)
            sum += a[i--] - '0';

        if (j >= 0)
            sum += b[j--] - '0';

        ans.push_back(char('0' + (sum % 2)));
        carry = sum / 2;
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    string a, b;
    cin >> a >> b;

    cout << addBinary(a, b) << "\n";
    return 0;
}
