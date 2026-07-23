#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int timeRequiredToBuy(vector<int>& tickets, int k) {
    int time = 0;

    for (int i = 0; i < tickets.size(); i++) {
        if (i <= k) {
            time += min(tickets[i], tickets[k]);
        } else {
            time += min(tickets[i], tickets[k] - 1);
        }
    }

    return time;
}

int main() {
    vector<int> tickets = {2, 3, 2};
    int k = 2;

    cout << timeRequiredToBuy(tickets, k) << endl;

    return 0;
}