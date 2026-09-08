import java.util.Scanner;
import java.util.Arrays;

public class Question2 {

    // This class stores one activity
    static class Activity {

        // Starting time of the activity
        int start;

        // Ending time of the activity
        int end;

        // Constructor
        Activity(int start, int end) {
            this.start = start;
            this.end = end;
        }
    }

    // Function to find the maximum number of activities
    static int maxActivities(int[] start, int[] end, int n) {

        // Create an array of Activity objects
        Activity[] activities = new Activity[n];

        // Put start and end time together
        for (int i = 0; i < n; i++) {
            activities[i] = new Activity(start[i], end[i]);
        }

        // Sort activities according to their END time
        //
        // We want the activity that finishes earliest
        // to come first.
        Arrays.sort(activities, (a, b) -> a.end - b.end);

        // This stores the number of activities selected
        int count = 0;

        // This stores the ending time of the
        // last activity we selected
        //
        // We start with -1 because activities
        // have non-negative times in this example.
        int lastEndTime = -1;

        // Go through every activity
        for (int i = 0; i < n; i++) {

            // Check if this activity starts
            // after or exactly when the previous
            // activity ends.
            if (activities[i].start >= lastEndTime) {

                // Select this activity
                count++;

                // Update the ending time
                lastEndTime = activities[i].end;
            }
        }

        // Return the maximum number of activities
        return count;
    }

    public static void main(String[] args) {

        // Scanner is used to take input from the user
        Scanner sc = new Scanner(System.in);

        // Take the number of activities
        System.out.print("Enter number of activities: ");
        int n = sc.nextInt();

        // Create start and end arrays
        int[] start = new int[n];
        int[] end = new int[n];

        // Take start times
        System.out.println("Enter start times:");

        for (int i = 0; i < n; i++) {
            start[i] = sc.nextInt();
        }

        // Take end times
        System.out.println("Enter end times:");

        for (int i = 0; i < n; i++) {
            end[i] = sc.nextInt();
        }

        // Find maximum number of activities
        int result = maxActivities(start, end, n);

        // Print the answer
        System.out.println("Maximum number of activities = " + result);

        // Close Scanner
        sc.close();
    }
}