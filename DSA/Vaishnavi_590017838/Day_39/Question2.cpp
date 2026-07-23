#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int minimumRooms(vector<pair<int, int>>& meetings) {
    sort(meetings.begin(), meetings.end());
    priority_queue<int, vector<int>, greater<int>> rooms;
    for(auto meeting : meetings) {
        if(!rooms.empty() && rooms.top() <= meeting.first)
            rooms.pop();
        rooms.push(meeting.second);
    }
    return rooms.size();
}

int main() {
    int n;
    cout << "Enter the number of meetings: ";
    cin >> n;
    vector<pair<int, int>> meetings;
    cout << "Enter the start and end time of each meeting:\n";
    for(int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;
        meetings.push_back({start, end});
    }
    cout << "Minimum conference rooms required: "
         << minimumRooms(meetings);
    return 0;
}
