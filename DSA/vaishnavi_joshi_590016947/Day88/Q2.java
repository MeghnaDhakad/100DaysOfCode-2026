import java.util.*;

class Solution {

    static class Job {
        int deadline;
        int profit;

        Job(int deadline, int profit) {
            this.deadline = deadline;
            this.profit = profit;
        }
    }

    public static long jobSequencing(int[] deadline, int[] profit) {

        int n = deadline.length;

        // Create jobs
        Job[] jobs = new Job[n];

        for (int i = 0; i < n; i++) {
            jobs[i] = new Job(deadline[i], profit[i]);
        }

        // Sort jobs by profit in descending order
        Arrays.sort(jobs, (a, b) -> b.profit - a.profit);

        // Find maximum deadline
        int maxDeadline = 0;

        for (int d : deadline) {
            maxDeadline = Math.max(maxDeadline, d);
        }

        // slot[i] tells whether time slot i is occupied
        boolean[] slot = new boolean[maxDeadline + 1];

        long totalProfit = 0;

        // Schedule each job
        for (Job job : jobs) {

            // Try to schedule the job as late as possible
            for (int time = job.deadline; time >= 1; time--) {

                if (!slot[time]) {
                    slot[time] = true;
                    totalProfit += job.profit;
                    break;
                }
            }
        }

        return totalProfit;
    }
}