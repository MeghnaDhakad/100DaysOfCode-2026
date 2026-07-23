import java.util.*;

public class Question2 {

    public static int minMeetingRooms(int[][] intervals) {

        if (intervals == null || intervals.length == 0) {
            return 0;
        }

        Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));

        PriorityQueue<Integer> minHeap = new PriorityQueue<>();

        for (int[] interval : intervals) {

            int start = interval[0];
            int end = interval[1];

            if (!minHeap.isEmpty() && minHeap.peek() <= start) {
                minHeap.poll();
            }

            minHeap.offer(end);
        }

        return minHeap.size();
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        String input = sc.nextLine();

        String[] numbers = input.replaceAll("[^0-9]+", " ")
                                .trim()
                                .split("\\s+");

        int n = numbers.length / 2;

        int[][] intervals = new int[n][2];

        int index = 0;

        for (int i = 0; i < n; i++) {
            intervals[i][0] = Integer.parseInt(numbers[index++]);
            intervals[i][1] = Integer.parseInt(numbers[index++]);
        }

        int result = minMeetingRooms(intervals);

        System.out.println(result);

        sc.close();
    }
}