import java.util.*;

public class Main {

    static class Job {
        int deadline;
        long profit;

        Job(int deadline, long profit) {
            this.deadline = deadline;
            this.profit = profit;
        }
    }

    static int find(int[] parent, int x) {
        if (parent[x] == x) {
            return x;
        }

        return parent[x] = find(parent, parent[x]);
    }

    static long maxProfit(int[] deadline, long[] profit) {
        int n = deadline.length;

        Job[] jobs = new Job[n];

        int maxDeadline = 0;

        for (int i = 0; i < n; i++) {
            jobs[i] = new Job(deadline[i], profit[i]);
            maxDeadline = Math.max(maxDeadline, deadline[i]);
        }

        Arrays.sort(jobs, (a, b) -> Long.compare(b.profit, a.profit));

        int[] parent = new int[maxDeadline + 1];

        for (int i = 0; i <= maxDeadline; i++) {
            parent[i] = i;
        }

        long totalProfit = 0;

        for (Job job : jobs) {

            int slot = find(parent, Math.min(job.deadline, maxDeadline));

            if (slot > 0) {

                totalProfit += job.profit;

                parent[slot] = find(parent, slot - 1);
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