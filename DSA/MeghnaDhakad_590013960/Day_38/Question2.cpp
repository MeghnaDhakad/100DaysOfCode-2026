#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> cardTrick(int n) {
    queue<int> q;
    vector<int> ans(n);

    for (int i = 0; i < n; i++)
        q.push(i);

    for (int card = 1; card <= n; card++) {
        ans[q.front()] = card;
        q.pop();

        if (!q.empty()) {
            q.push(q.front());
            q.pop();
        }
    }

    return ans;
}

int main() {
    int n = 4;

    vector<int> ans = cardTrick(n);

    for (int x : ans)
        cout << x << " ";

    return 0;
}