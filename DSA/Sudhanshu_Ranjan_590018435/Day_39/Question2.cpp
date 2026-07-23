#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int minMeetingRooms(vector<vector<int>>& intervals) {
    if (intervals.empty())
        return 0;

    sort(intervals.begin(), intervals.end());

    priority_queue<int, vector<int>, greater<int>> pq;

    for (auto &meeting : intervals) {
        if (!pq.empty() && pq.top() <= meeting[0])
            pq.pop();

        pq.push(meeting[1]);
    }

    return pq.size();
}