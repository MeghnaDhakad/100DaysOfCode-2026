class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {

        if (intervals.empty())
            return 0;

        // Sort meetings by start time
        sort(intervals.begin(), intervals.end());

        // Min heap to store ending times
        priority_queue<int, vector<int>, greater<int>> pq;

        // First meeting occupies one room
        pq.push(intervals[0][1]);

        for (int i = 1; i < intervals.size(); i++) {

            // If the earliest meeting is over,
            // reuse that room
            if (intervals[i][0] >= pq.top()) {
                pq.pop();
            }

            // Allocate room for current meeting
            pq.push(intervals[i][1]);
        }

        return pq.size();
    }
};
