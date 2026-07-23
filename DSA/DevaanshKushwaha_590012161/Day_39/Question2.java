import java.util.Arrays;
import java.util.PriorityQueue;

class Solution {
    public int minMeetingRooms(int[][] intervals) {
        if (intervals == null || intervals.length == 0) {
            return 0;
        }

        // Sort meetings by start time
        Arrays.sort(intervals, (a, b) -> a[0] - b[0]);

        // Min-heap of end times of currently occupied rooms
        PriorityQueue<Integer> endTimes = new PriorityQueue<>();

        int maxRooms = 0;

        for (int[] meeting : intervals) {
            int start = meeting[0];
            int end = meeting[1];

            // Free up any room whose meeting has already ended by 'start'
            if (!endTimes.isEmpty() && endTimes.peek() <= start) {
                endTimes.poll();
            }

            endTimes.offer(end);
            maxRooms = Math.max(maxRooms, endTimes.size());
        }

        return maxRooms;
    }
}
