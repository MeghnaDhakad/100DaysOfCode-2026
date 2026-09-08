import java.util.*;

public class Main {

    static class Activity {
        long start;
        long end;

        Activity(long start, long end) {
            this.start = start;
            this.end = end;
        }
    }

    static int maxActivities(long[] start, long[] end) {
        int n = start.length;

        Activity[] activities = new Activity[n];

        for (int i = 0; i < n; i++) {
            activities[i] = new Activity(start[i], end[i]);
        }

        Arrays.sort(activities, (a, b) -> Long.compare(a.end, b.end));

        int count = 0;
        long lastEnd = Long.MIN_VALUE;

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

        long[] start = new long[n];
        long[] end = new long[n];

        for (int i = 0; i < n; i++) {
            start[i] = sc.nextLong();
        }

        for (int i = 0; i < n; i++) {
            end[i] = sc.nextLong();
        }

        System.out.println(maxActivities(start, end));

        sc.close();
    }
}