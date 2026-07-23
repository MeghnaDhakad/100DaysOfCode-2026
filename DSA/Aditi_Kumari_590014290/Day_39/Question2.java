/* Minimum Conference Rooms Required
Explanation
Write an efficient function to find the minimum number of conference rooms required so no two overlapping meetings share a room.

Example
Input: intervals = [[1, 5], [2, 6], [4, 8], [9, 10]]. Output: 3.*/
package Day_39;
import java.util.*;
public class Question2 {
    public int minMeetingRooms(int[][] intervals) {
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
