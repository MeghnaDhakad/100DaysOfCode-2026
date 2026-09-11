import java.util.*;

class Solution {
    
    static class Job {
        int id;
        int deadline;
        int profit;

        Job(int id, int deadline, int profit) {
            this.id = id;
            this.deadline = deadline;
            this.profit = profit;
        }
    }

    public static int jobScheduling(Job[] jobs) {
        Arrays.sort(jobs, (a, b) -> b.profit - a.profit);

        int maxDeadline = 0;

        for (Job job : jobs) {
            maxDeadline = Math.max(maxDeadline, job.deadline);
        }

        int[] slots = new int[maxDeadline + 1];
        Arrays.fill(slots, -1);

        int totalProfit = 0;

        for (Job job : jobs) {

            for (int slot = job.deadline; slot >= 1; slot--) {

                if (slots[slot] == -1) {
                    slots[slot] = job.id;
                    totalProfit += job.profit;
                    break;
                }
            }
        }

        return totalProfit;
    }
}
