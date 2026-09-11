import java.util.Arrays;
import java.util.Comparator;

class Solution {
    static class Job {
        int deadline, profit;
        Job(int deadline, int profit) {
            this.deadline = deadline;
            this.profit = profit;
        }
    }

    public int jobScheduling(int[] deadline, int[] profit) {
        int n = deadline.length;
        Job[] jobs = new Job[n];
        int maxDeadline = 0;

        for (int i = 0; i < n; i++) {
            jobs[i] = new Job(deadline[i], profit[i]);
            maxDeadline = Math.max(maxDeadline, deadline[i]);
        }

        // Sort jobs by profit descending
        Arrays.sort(jobs, (a, b) -> b.profit - a.profit);

        // slot[i] = true if time slot i is occupied (1-indexed slots, 1..maxDeadline)
        boolean[] slot = new boolean[maxDeadline + 1];
        int totalProfit = 0;

        for (Job job : jobs) {
            // Try to place this job in the latest free slot <= its deadline
            for (int t = job.deadline; t >= 1; t--) {
                if (!slot[t]) {
                    slot[t] = true;
                    totalProfit += job.profit;
                    break;
                }
            }
        }

        return totalProfit;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] deadline = {4, 1, 1, 1};
        int[] profit = {20, 10, 40, 30};
        System.out.println(sol.jobScheduling(deadline, profit)); // 60
    }
}
