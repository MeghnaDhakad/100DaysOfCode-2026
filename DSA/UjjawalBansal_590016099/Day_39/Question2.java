import java.util.Arrays;
import java.util.Scanner;

public class Question2 {

    public static int minMeetingRooms(int[][] intervals) {
        if (intervals == null || intervals.length == 0) {
            return 0;
        }

        int n = intervals.length;
        int[] start = new int[n];
        int[] end = new int[n];

        for (int i = 0; i < n; i++) {
            start[i] = intervals[i][0];
            end[i] = intervals[i][1];
        }

        Arrays.sort(start);
        Arrays.sort(end);

        int rooms = 0;
        int maxRooms = 0;
        
        int startPointer = 0;
        int endPointer = 0;

        while (startPointer < n) {
            if (start[startPointer] < end[endPointer]) {
                rooms++;
                startPointer++;
                
                maxRooms = Math.max(maxRooms, rooms);
            } 
            else {
                rooms--;
                endPointer++;
            }
        }

        return maxRooms;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        System.out.print("Enter the total number of meetings: ");
        int n = sc.nextInt();
            
        if (n <= 0) {
            System.out.println("Minimum conference rooms required: 0");
            return;
        }

        int[][] intervals = new int[n][2];

        System.out.println("Enter the start and end times for each meeting (e.g., '0 30'):");
        for (int i = 0; i < n; i++) {
            System.out.print("Meeting " + (i + 1) + ": ");
            intervals[i][0] = sc.nextInt();
            intervals[i][1] = sc.nextInt();
            
            if (intervals[i][0] >= intervals[i][1]) {
                System.out.println("Error: Start time must be strictly less than end time. Please restart.");
                return;
            }
        }

        int requiredRooms = minMeetingRooms(intervals);
        System.out.println("\nMinimum conference rooms required: " + requiredRooms);
        sc.close();
    }
}