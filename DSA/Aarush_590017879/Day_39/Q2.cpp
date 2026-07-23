#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minConferenceRooms(vector<vector<int>>& intervals) {
    int n = intervals.size();

    if (n == 0) {
        return 0;
    }

    vector<int> start(n);
    vector<int> end(n);

    for (int i = 0; i < n; i++) {
        start[i] = intervals[i][0];
        end[i] = intervals[i][1];
    }

    sort(start.begin(), start.end());
    sort(end.begin(), end.end());

    int i = 0;
    int j = 0;
    int rooms = 0;
    int maxRooms = 0;

    while (i < n) {
        if (start[i] < end[j]) {
            rooms++;
            maxRooms = max(maxRooms, rooms);
            i++;
        } else {
            rooms--;
            j++;
        }
    }

    return maxRooms;
}

int main() {
    vector<vector<int>> intervals = {
        {1, 5},
        {2, 6},
        {4, 8},
        {9, 10}
    };

    cout << minConferenceRooms(intervals) << endl;

    return 0;
}