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
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        int[] deadline = new int[n];
        long[] profit = new long[n];

        for (int i = 0; i < n; i++) {
            deadline[i] = sc.nextInt();
        }

        for (int i = 0; i < n; i++) {
            profit[i] = sc.nextLong();
        }

        System.out.println(maxProfit(deadline, profit));

        sc.close();
    }
}