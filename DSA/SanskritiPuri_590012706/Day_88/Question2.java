import java.util.*;

class Solution {
    public long jobSequencing(int[] deadline, int[] profit) {
        int n = deadline.length;

        Integer[] jobs = new Integer[n];

        for (int i = 0; i < n; i++) {
            jobs[i] = i;
        }

        // Sort jobs by decreasing profit
        Arrays.sort(jobs, (a, b) -> Integer.compare(profit[b], profit[a]));

        int maxDeadline = 0;

        for (int d : deadline) {
            maxDeadline = Math.max(maxDeadline, d);
        }

        boolean[] slot = new boolean[maxDeadline + 1];

        long totalProfit = 0;

        for (int i : jobs) {
            // Find latest available slot before deadline
            for (int j = deadline[i]; j >= 1; j--) {
                if (!slot[j]) {
                    slot[j] = true;
                    totalProfit += profit[i];
                    break;
                }
            }
        }

        return totalProfit;
    }
}
