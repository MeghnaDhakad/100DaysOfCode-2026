import java.util.*;
public class Main {
    public static int minConferenceRooms(int[][] intervals) {
        if (intervals.length == 0)
            return 0;
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        pq.offer(intervals[0][1]);
        for (int i = 1; i < intervals.length; i++) {
            if (intervals[i][0] >= pq.peek()) {
                pq.poll();
            }
            pq.offer(intervals[i][1]);
        }
        return pq.size();
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of meetings: ");
        int n = sc.nextInt();
        int[][] intervals = new int[n][2];
        System.out.println("Enter start and end time of each meeting:");
        for (int i = 0; i < n; i++) {
            intervals[i][0] = sc.nextInt();
            intervals[i][1] = sc.nextInt();
        }
        int result = minConferenceRooms(intervals);
        System.out.println("Minimum Conference Rooms Required: " + result);
        sc.close();
    }
}
