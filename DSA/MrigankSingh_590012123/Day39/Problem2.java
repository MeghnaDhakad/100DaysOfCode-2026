import java.util.Arrays;

public class Problem2 {
    public int minMeetingRooms(int[][] intervals) {
        int n = intervals.length;
        int[] starts = new int[n];
        int[] ends = new int[n];

        for (int i = 0; i < n; i++) {
            starts[i] = intervals[i][0];
            ends[i] = intervals[i][1];
        }

        Arrays.sort(starts);
        Arrays.sort(ends);

        int startPointer = 0;
        int endPointer = 0;
        int activeRooms = 0;
        int maxRooms = 0;

        while (startPointer < n) {
            if (starts[startPointer] < ends[endPointer]) {
                activeRooms++;
                maxRooms = Math.max(maxRooms, activeRooms);
                startPointer++;
            } else {
                activeRooms--;
                endPointer++;
            }
        }

        return maxRooms;
    }
}