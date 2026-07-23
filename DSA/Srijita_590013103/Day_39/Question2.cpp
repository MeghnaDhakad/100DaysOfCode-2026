class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {

        if(intervals.empty())
            return 0;


        sort(intervals.begin(), intervals.end());


        priority_queue<int, vector<int>, greater<int>> pq;

 
        pq.push(intervals[0][1]);

        for(int i = 1; i < intervals.size(); i++) {

            int start = intervals[i][0];
            int end = intervals[i][1];


            if(start >= pq.top()) {
                pq.pop();
            }

  
            pq.push(end);
        }


        return pq.size();
    }
};