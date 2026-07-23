#include <iostream>
#include <deque>
#include <vector>
using namespace std;

vector<int> cardTrick(int n) {
    deque<int> dq;

    for (int i = n; i >= 1; i--) {

        if (!dq.empty()) {
            int last = dq.back();
            dq.pop_back();
            dq.push_front(last);
        }
        dq.push_front(i);
    }

    vector<int> ans;

    while (!dq.empty()) {
        ans.push_back(dq.front());
        dq.pop_front();
    }

    return ans;
}

int main() {
    int n;

    cout << "Enter number of cards: ";
    cin >> n;

    vector<int> ans = cardTrick(n);

    cout << "Initial arrangement: ";

    for (int x : ans)
        cout << x << " ";

    cout << endl;

    return 0;
}