#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int printerQueue(vector<int>& priorities, int location) {
    queue<pair<int, int>> q;
    priority_queue<int> pq;

    for (int i = 0; i < priorities.size(); i++) {
        q.push({priorities[i], i});
        pq.push(priorities[i]);
    }

    int minutes = 0;

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        if (cur.first == pq.top()) {
            pq.pop();
            minutes++;

            if (cur.second == location)
                return minutes;
        } else {
            q.push(cur);
        }
    }

    return -1;
}

int main() {
    vector<int> priorities = {2, 1, 3, 2};
    int location = 2;

    cout << printerQueue(priorities, location);

    return 0;
}