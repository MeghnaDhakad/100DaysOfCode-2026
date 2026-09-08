import java.util.*;

public class Question2 {

    static class Activity {
        int start;
        int end;

        Activity(int start, int end) {
            this.start = start;
            this.end = end;
        }
    }

    public static int maxActivities(int[] start, int[] end) {
        int n = start.length;

        Activity[] activities = new Activity[n];

        for (int i = 0; i < n; i++) {
            activities[i] = new Activity(start[i], end[i]);
        }

        Arrays.sort(activities, (a, b) -> Integer.compare(a.end, b.end));

        int count = 0;
        int lastEnd = -1;

        for (Activity activity : activities) {
            if (activity.start >= lastEnd) {
                count++;
                lastEnd = activity.end;
            }
        }

        return count;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        int[] start = new int[n];
        int[] end = new int[n];

        for (int i = 0; i < n; i++) {
            start[i] = sc.nextInt();
        }

        for (int i = 0; i < n; i++) {
            end[i] = sc.nextInt();
        }

        System.out.println(maxActivities(start, end));

        sc.close();
    }
}