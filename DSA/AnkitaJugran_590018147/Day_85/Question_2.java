import java.util.*;

class Max_No_of_Activity {

    public static int maxActivities(int[] start, int[] end) {

        int n = start.length;

        // Store each activity as {start, end}
        int[][] activities = new int[n][2];

        for (int i = 0; i < n; i++) {
            activities[i][0] = start[i];
            activities[i][1] = end[i];
        }

        // Sort activities by end time
        Arrays.sort(activities, (a, b) -> a[1] - b[1]);

        int count = 0;
        int previousEnd = -1;

        // Greedy selection
        for (int i = 0; i < n; i++) {

            if (activities[i][0] >= previousEnd) {
                count++;
                previousEnd = activities[i][1];
            }
        }

        return count;
    }

    public static void main(String[] args) {

        int[] start = {1, 3, 0, 5, 8, 5};
        int[] end = {2, 4, 6, 7, 9, 9};

        int result = maxActivities(start, end);

        System.out.println("Maximum number of activities: " + result);
    }
}