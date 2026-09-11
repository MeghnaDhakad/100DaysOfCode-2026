
import java.util.*;
class JS{
    static class Job {
        int deadline;
        int profit;
        Job(int deadline, int profit) {
            this.deadline = deadline;
            this.profit = profit;
        }
    }
    public static int maxProfit(int[] deadline, int[] profit) {
        int n = deadline.length;
        Job[] jobs = new Job[n];
        for (int i = 0; i < n; i++) {
            jobs[i] = new Job(deadline[i], profit[i]);
        }
        Arrays.sort(jobs, (a, b) -> b.profit - a.profit);
        int maxDeadline = 0;
        for (Job job : jobs) {
            maxDeadline = Math.max(maxDeadline, job.deadline);
        }
        boolean[] slot = new boolean[maxDeadline + 1];
        int totalProfit = 0;
        for (Job job : jobs) {
            for (int j = job.deadline; j >= 1; j--) {
                if (slot[j]) {
                    slot[j] = true;
                    totalProfit += job.profit;
                    break;
                }
            }
        }
        return totalProfit;
    }
    public static void main(String[] args) {
        int[] deadline = {4, 1, 1, 1};
        int[] profit = {20, 10, 40, 30};
        int answer = maxProfit(deadline, profit);
        System.out.println("Maximum Profit:" + answer);
    }
}