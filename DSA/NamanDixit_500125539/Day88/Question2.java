import java.util.Scanner;
import java.util.Arrays;

public class Question2 {

    // This class stores one job
    static class Job {

        // Deadline of the job
        int deadline;

        // Profit of the job
        int profit;

        // Constructor
        Job(int deadline, int profit) {
            this.deadline = deadline;
            this.profit = profit;
        }
    }

    // Function to find maximum profit
    static int jobSequencing(int[] deadline, int[] profit, int n) {

        // Create an array of jobs
        Job[] jobs = new Job[n];

        // Put deadline and profit together
        for (int i = 0; i < n; i++) {
            jobs[i] = new Job(deadline[i], profit[i]);
        }

        // Sort jobs by PROFIT
        // Highest profit should come first
        Arrays.sort(jobs, (a, b) -> b.profit - a.profit);

        // Find the maximum deadline
        int maxDeadline = 0;

        for (int i = 0; i < n; i++) {

            if (jobs[i].deadline > maxDeadline) {
                maxDeadline = jobs[i].deadline;
            }
        }

        // Create slots for the jobs
        //
        // slot[1] = first time slot
        // slot[2] = second time slot
        // and so on...
        boolean[] slot = new boolean[maxDeadline + 1];

        // This stores the total profit
        int totalProfit = 0;

        // Go through every job
        for (int i = 0; i < n; i++) {

            // Start checking from the job's deadline
            int time = jobs[i].deadline;

            // Try to find an empty slot
            // before or on the deadline
            while (time > 0) {

                // If this slot is empty
                if (slot[time] == false) {

                    // Put the job in this slot
                    slot[time] = true;

                    // Add the job's profit
                    totalProfit = totalProfit + jobs[i].profit;

                    // Job is scheduled, so stop searching
                    break;
                }

                // If the slot is already occupied,
                // try the previous slot
                time--;
            }
        }

        // Return the maximum profit
        return totalProfit;
    }

    public static void main(String[] args) {

        // Scanner is used to take input from the user
        Scanner sc = new Scanner(System.in);

        // Take number of jobs
        System.out.print("Enter number of jobs: ");
        int n = sc.nextInt();

        // Create deadline array
        int[] deadline = new int[n];

        // Create profit array
        int[] profit = new int[n];

        // Take deadlines
        System.out.println("Enter the deadlines:");

        for (int i = 0; i < n; i++) {
            deadline[i] = sc.nextInt();
        }

        // Take profits
        System.out.println("Enter the profits:");

        for (int i = 0; i < n; i++) {
            profit[i] = sc.nextInt();
        }

        // Find maximum profit
        int result = jobSequencing(deadline, profit, n);

        // Print the answer
        System.out.println("Maximum profit = " + result);

        // Close Scanner
        sc.close();
    }
}