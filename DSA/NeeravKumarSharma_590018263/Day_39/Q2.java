import java.util.Arrays;

public class Q2 {

    public static int minConferenceRooms(int[][] intervals) {
        if (intervals == null || intervals.length == 0) {
            return 0;
        }

        int n = intervals.length;
        int[] startTimes = new int[n];
        int[] endTimes = new int[n];

        for (int i = 0; i < n; i++) {
            startTimes[i] = intervals[i][0];
            endTimes[i] = intervals[i][1];
        }

        Arrays.sort(startTimes);
        Arrays.sort(endTimes);

        int startPointer = 0, endPointer = 0;
        int activeRooms = 0, maxRooms = 0;

        while (startPointer < n) {
            if (startTimes[startPointer] < endTimes[endPointer]) {
                activeRooms++;
                startPointer++;
            } 
            else {
                activeRooms--;
                endPointer++;
            }
            
            maxRooms = Math.max(maxRooms, activeRooms);
        }

        return maxRooms;
    }
    public static void main(String[] args) {
        int[][] intervals = {{1, 5}, {2, 6}, {4, 8}, {9, 10}};
        System.out.println("Output: " + minConferenceRooms(intervals));
    }

}