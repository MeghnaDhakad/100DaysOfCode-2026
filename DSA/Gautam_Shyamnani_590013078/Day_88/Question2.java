import java.util.*;

public class Question2 {

    static class Job {
        int deadline;
        long profit;

        Job(int deadline, long profit) {
            this.deadline = deadline;
            this.profit = profit;
        }
    }

    public static long maxProfit(int[] deadline, long[] profit) {
        int n = deadline.length;

        Job[] jobs = new Job[n];

        for (int i = 0; i < n; i++) {
            jobs[i] = new Job(deadline[i], profit[i]);
        }

        Arrays.sort(jobs, (a, b) -> Long.compare(b.profit, a.profit));

        int maxDeadline = 0;

        for (int d : deadline) {
            maxDeadline = Math.max(maxDeadline, d);
        }

        boolean[] slot = new boolean[maxDeadline + 1];

        long totalProfit = 0;

        for (Job job : jobs) {

            for (int j = job.deadline; j >= 1; j--) {

                if (!slot[j]) {
                    slot[j] = true;
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
        long[] profit = {20, 10, 40, 30};

        System.out.println(maxProfit(deadline, profit));
    }
}