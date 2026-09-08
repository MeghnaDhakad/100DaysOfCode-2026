import java.util.*;

public class Question2 {
    public static int maximumActivities(int[] start, int[] end) {
        int n = start.length;
        int[][] activities = new int[n][2];

        for (int i = 0; i < n; i++) {
            activities[i][0] = start[i];
            activities[i][1] = end[i];
        }
        Arrays.sort(activities, (a, b) -> Integer.compare(a[1], b[1]));

        int count = 0;
        int last = -1;
        for (int i = 0; i < n; i++) {
            if (activities[i][0] >= last) {
                count++;
                last = activities[i][1];
            }
        }
        return count;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the number of activities: ");
        int n = sc.nextInt();

        int[] start = new int[n];
        int[] end = new int[n];

        System.out.println("Enter the start times:");
        for (int i = 0; i < n; i++) {
            start[i] = sc.nextInt();
        }

        System.out.println("Enter the end times:");
        for (int i = 0; i < n; i++) {
            end[i] = sc.nextInt();
        }
        System.out.println("Start times: " + Arrays.toString(start));
        System.out.println("End times: " + Arrays.toString(end));
        System.out.println("Maximum number of non-overlapping activities: " + maximumActivities(start, end));
        sc.close();
    }
}