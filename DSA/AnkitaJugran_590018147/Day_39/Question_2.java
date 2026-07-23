package Queue;
import java.util.Arrays;
import java.util.PriorityQueue;

public class MinConferenceRooms {

    public static int minMeetingRooms(int[][] intervals) {

        if (intervals.length == 0) {
            return 0;
        }

        // Sort meetings by start time
        Arrays.sort(intervals, (a, b) -> a[0] - b[0]);

        // Min Heap to store end times
        PriorityQueue<Integer> pq = new PriorityQueue<>();

        // Add first meeting's end time
        pq.offer(intervals[0][1]);

        // Process remaining meetings
        for (int i = 1; i < intervals.length; i++) {

            // If the earliest meeting has ended,
            // reuse the room
            if (intervals[i][0] >= pq.peek()) {
                pq.poll();
            }

            // Add current meeting's end time
            // new room
            pq.offer(intervals[i][1]);
        }

        return pq.size();
    }

    public static void main(String[] args) {

        int[][] intervals = {
                {0, 30},
                {5, 10},
                {15, 20}
        };

        System.out.println("Minimum Conference Rooms Required: "
                + minMeetingRooms(intervals));
    }
    

}
