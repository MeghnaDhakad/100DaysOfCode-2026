import java.util.*;

class Solution {
    public int maxActivities(int n, int[] start, int[] end) {
        // Pair up (start, end) and sort by end time
        int[][] activities = new int[n][2];
        for (int i = 0; i < n; i++) {
            activities[i][0] = start[i];
            activities[i][1] = end[i];
        }

        Arrays.sort(activities, (a, b) -> a[1] - b[1]); // sort by end time

        int count = 1;                 // first activity (earliest finish) is always selected
        int lastEnd = activities[0][1];

        for (int i = 1; i < n; i++) {
            if (activities[i][0] >= lastEnd) { // non-overlapping check
                count++;
                lastEnd = activities[i][1];
            }
        }

        return count;
    }
}
