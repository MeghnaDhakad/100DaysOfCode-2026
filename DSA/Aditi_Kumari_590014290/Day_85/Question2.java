package DSA.Aditi_Kumari_590014290.Day_85;
import java.util.*;
public class Question2 {
    public static int maxActivities(int n, int[] start, int[] end) {
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
}