import java.util.*;

class Job {
    int deadline;
    int profit;

    Job(int deadline, int profit) {
        this.deadline = deadline;
        this.profit = profit;
    }
}

class Solution {
    public static long jobSequencing(int n, int[] deadline, int[] profit) {

        Job[] jobs = new Job[n];

        for (int i = 0; i < n; i++) {
            jobs[i] = new Job(deadline[i], profit[i]);
        }

        // Sort jobs in decreasing order of profit
        Arrays.sort(jobs, (a, b) -> b.profit - a.profit);

        int maxDeadline = 0;

        for (int d : deadline) {
            maxDeadline = Math.max(maxDeadline, d);
        }

        boolean[] slot = new boolean[maxDeadline + 1];

        long totalProfit = 0;

        for (Job job : jobs) {

            // Try to place the job in the latest
            // available slot before its deadline
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

    public static void main(String[] args) {

        int n = 4;

        int[] deadline = {4, 1, 1, 1};
        int[] profit = {20, 10, 40, 30};

        System.out.println(jobSequencing(n, deadline, profit));
    }
}
