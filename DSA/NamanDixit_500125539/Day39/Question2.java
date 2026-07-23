
import java.util.Arrays;
import java.util.Scanner;

public class Question2 {

    // Function to find minimum conference rooms
    public static int minRooms(int[][] intervals) {

        int n = intervals.length;

        // Array to store start times
        int[] start = new int[n];

        // Array to store end times
        int[] end = new int[n];

        // Copy start and end times
        for (int i = 0; i < n; i++) {

            start[i] = intervals[i][0];
            end[i] = intervals[i][1];
        }

        // Sort both arrays
        Arrays.sort(start);
        Arrays.sort(end);

        // Pointer for start times
        int i = 0;

        // Pointer for end times
        int j = 0;

        // Current rooms in use
        int rooms = 0;

        // Maximum rooms needed
        int maxRooms = 0;

        // Compare start and end times
        while (i < n) {

            // Meeting starts before another ends
            if (start[i] < end[j]) {

                rooms++;

                // Update answer
                maxRooms = Math.max(maxRooms, rooms);

                i++;
            } // A meeting has ended
            else {

                rooms--;

                j++;
            }
        }

        return maxRooms;
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        // Input number of meetings
        System.out.print("Enter number of meetings: ");
        int n = sc.nextInt();

        int[][] intervals = new int[n][2];

        // Input meetings
        System.out.println("Enter start time and end time:");

        for (int i = 0; i < n; i++) {

            intervals[i][0] = sc.nextInt();
            intervals[i][1] = sc.nextInt();
        }

        // Find answer
        int answer = minRooms(intervals);

        // Print answer
        System.out.println("Minimum Conference Rooms Required = " + answer);

        sc.close();
    }
}

