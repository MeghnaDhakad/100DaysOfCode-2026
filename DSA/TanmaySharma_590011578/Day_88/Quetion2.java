import java.util.*;

public class Question2 {

    static void jobSequencing(int[] deadline, int[] profit) {
        int n = deadline.length;

        int[][] jobs = new int[n][2];

        for (int i = 0; i < n; i++) {
            jobs[i][0] = deadline[i];
            jobs[i][1] = profit[i];
        }

        Arrays.sort(jobs, (a, b) -> b[1] - a[1]);

        int maxDeadline = 0;
        for (int d : deadline) {
            maxDeadline = Math.max(maxDeadline, d);
        }

        boolean[] slot = new boolean[maxDeadline + 1];
        int totalProfit = 0;

        for (int i = 0; i < n; i++) {
            for (int j = Math.min(maxDeadline, jobs[i][0]); j >= 1; j--) {
                if (!slot[j]) {
                    slot[j] = true;
                    totalProfit += jobs[i][1];
                    break;
                }
            }
        }

        System.out.println(totalProfit);
    }

    public static void main(String[] args) {
        int[] deadline = {4, 1, 1, 1};
        int[] profit = {20, 10, 40, 30};

        jobSequencing(deadline, profit);
    }
}