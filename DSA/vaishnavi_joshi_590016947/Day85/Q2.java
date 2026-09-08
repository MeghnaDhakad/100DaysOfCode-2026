import java.util.*;

class Solution {
    public int maxActivities(int[] start, int[] end) {

        int n = start.length;

        // Store activities as {start, end}
        int[][] activities = new int[n][2];

        for (int i = 0; i < n; i++) {
            activities[i][0] = start[i];
            activities[i][1] = end[i];
        }

        // Sort activities by ending time
        Arrays.sort(activities, (a, b) -> Integer.compare(a[1], b[1]));

        int count = 0;
        int lastEnd = -1;

        for (int i = 0; i < n; i++) {

            // Activity does not overlap
            if (activities[i][0] >= lastEnd) {
                count++;
                lastEnd = activities[i][1];
            }
        }

        return count;
    }
}