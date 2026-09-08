
import java.util.*;
class MA{
    public static int maxActivities(int[] start, int[] end) {
        int n = start.length;
        int[][] activities = new int[n][2];
        for (int i = 0; i < n; i++) {
            activities[i][0] = start[i];
            activities[i][1] = end[i];
        }
        Arrays.sort(activities, (a, b) -> a[1] - b[1]);
        int count = 0;
        int lastEnd = -1;
        for (int i = 0; i < n; i++) {
            if (activities[i][0] >= lastEnd) {
                count++;
                lastEnd = activities[i][1];
            }
        }
        return count;
    }
    public static void main(String[] args) {
        int[] start = {1, 3, 0, 5, 8, 5};
        int[] end = {2, 4, 6, 7, 9, 9};
        int answer = maxActivities(start, end);
        System.out.println("Maximum activities:" + answer);
    }
}