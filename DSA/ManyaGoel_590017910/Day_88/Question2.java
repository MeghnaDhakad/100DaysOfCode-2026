import java.util.*;

public class Question2 {
    public static class Job {
        int deadline;
        long profit;
        Job(int deadline, long profit) {
            this.deadline = deadline;
            this.profit = profit;
        }
    }

    public static class SlotManager{
        int[] parent;

        SlotManager(int n) {
            parent = new int[n + 1];
            for (int i = 0; i <= n; i++) parent[i] = i;
        }

        int find(int x) {
            while (x != parent[x]) {
                parent[x] = parent[parent[x]];
                x = parent[x];
            }
            return x;
        }

        void occupy(int slot) {
            parent[slot] = find(slot - 1);
        }
    }

    public static long maxProfit(int[] deadline, long[] profit) {
        int n = deadline.length;
        Job[] jobs = new Job[n];
        int maxDeadline = 0;

        for (int i = 0; i < n; i++) {
            jobs[i] = new Job(deadline[i], profit[i]);
            maxDeadline = Math.max(maxDeadline, deadline[i]);
        }

        Arrays.sort(jobs, (a, b) -> Long.compare(b.profit, a.profit));

        int slots = Math.min(n, maxDeadline);
        SlotManager slotManager = new SlotManager(slots);
        long totalProfit = 0;
        for (Job job : jobs) {
            int slot = slotManager.find(Math.min(job.deadline, slots));
            if (slot > 0) {
                totalProfit += job.profit;
                slotManager.occupy(slot);
            }
        }
        return totalProfit;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the number of jobs: ");
        int n = sc.nextInt();

        int[] deadline = new int[n];
        long[] profit = new long[n];

        System.out.println("Enter the deadlines:");
        for (int i = 0; i < n; i++) {
            deadline[i] = sc.nextInt();
        }

        System.out.println("Enter the profits:");
        for (int i = 0; i < n; i++) {
            profit[i] = sc.nextLong();
        }

        long result = maxProfit(deadline, profit);

        System.out.println("Maximum total profit: " + result);

        sc.close();
    }
}