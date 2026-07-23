//Need to find the minimum number of conference rooms required

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
    vector<pair<int, int>> meetings = {
        {1, 5},
        {2, 6},
        {4, 8},
        {9, 10}
    };

    // sort meetings by start time
    sort(meetings.begin(), meetings.end());

    priority_queue<int, vector<int>, greater<int>> rooms;

    for (auto meeting : meetings)
    {
        // room becomes free before this meeting starts
        if (!rooms.empty() && rooms.top() <= meeting.first)
        {
            rooms.pop();
        }

        rooms.push(meeting.second);
    }

    cout << rooms.size();

    return 0;
}