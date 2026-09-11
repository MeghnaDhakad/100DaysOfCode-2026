import java.util.*;

class Solution {

    static class Job {
        int deadline;
        long profit;

        Job(int deadline, long profit) {
            this.deadline = deadline;
            this.profit = profit;
        }
    }

    public static long maxProfit(int n, int[] deadline, long[] profit) {

        Job[] jobs = new Job[n];

        for (int i = 0; i < n; i++) {
            jobs[i] = new Job(deadline[i], profit[i]);
        }

        Arrays.sort(jobs, (a, b) -> Long.compare(b.profit, a.profit));

        boolean[] slot = new boolean[100001];

        long totalProfit = 0;

        for (Job job : jobs) {

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