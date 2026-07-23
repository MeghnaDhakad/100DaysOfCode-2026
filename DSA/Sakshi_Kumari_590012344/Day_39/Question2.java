import java.util.*;

class Solution {
    public int minMeetingRooms(int[][] intervals) {
        if (intervals.length == 0) return 0;

        Arrays.sort(intervals, (a, b) -> a[0] - b[0]);

        PriorityQueue<Integer> pq = new PriorityQueue<>();

        for (int[] meeting : intervals) {
            if (!pq.isEmpty() && pq.peek() <= meeting[0]) {
                pq.poll();
            }
            pq.offer(meeting[1]);
        }

        return pq.size();
    }
}
