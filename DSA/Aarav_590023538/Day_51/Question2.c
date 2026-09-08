pp
#include <bits/stdc++.h>
using namespace std;

int firstInvalidRecord(vector<vector<string>>& deliveries) {
    // key: vendor_id + "#" + lot_number -> cert_code seen so far
    unordered_map<string, string> seen;

    for (int i = 0; i < (int)deliveries.size(); i++) {
        const string& vendor = deliveries[i][0];
        const string& lot    = deliveries[i][1];
        const string& cert   = deliveries[i][2];

        string key = vendor + "#" + lot;
        auto it = seen.find(key);

        if (it == seen.end()) {
            seen[key] = cert;
        } else if (it->second != cert) {
            return i;
        }
    }
    return -1;
}

int main() {
    vector<vector<string>> d1 = {
        {"V1","L100","A"}, {"V2","L200","B"}, {"V1","L100","A"}, {"V1","L100","C"}
    };
    cout << firstInvalidRecord(d1) << endl; // 3

    vector<vector<string>> d2 = {
        {"V1","L100","A"}, {"V1","L101","A"}, {"V2","L100","A"}
    };
    cout << firstInvalidRecord(d2) << endl; // -1

    vector<vector<string>> d3 = {
        {"V3","L500","X"}, {"V3","L500","Y"}
    };
    cout << firstInvalidRecord(d3) << endl; // 1

    return 0;
}
