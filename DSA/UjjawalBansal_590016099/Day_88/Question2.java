import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Question2 {
    public static long maxProfit(int[] deadline, int[] profit, int n) {
        
        int[][] jobs = new int[n][2];
        for (int i = 0; i < n; i++) {
            jobs[i][0] = deadline[i];
            jobs[i][1] = profit[i];
        }
        
        Arrays.sort(jobs, (a, b) -> Integer.compare(a[0], b[0]));
        
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        
        for (int i = 0; i < n; i++) {
            minHeap.add(jobs[i][1]);
            if (minHeap.size() > jobs[i][0]) {
                minHeap.poll();
            }
        }

        long totalProfit = 0;
        while (!minHeap.isEmpty()) {
            totalProfit += minHeap.poll();
        }
        
        return totalProfit;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        System.out.print("Enter the number of jobs: ");
        int n = sc.nextInt();
        
        int[] deadline = new int[n];
        System.out.print("Enter the " + n + " deadlines: ");
        for (int i = 0; i < n; i++) {
            deadline[i] = sc.nextInt();
        }
        
        int[] profit = new int[n];
        System.out.print("Enter the " + n + " profits: ");
        for (int i = 0; i < n; i++) {
            profit[i] = sc.nextInt();
        }
        
        long result = maxProfit(deadline, profit, n);
        System.out.println("Output: " + result);
        sc.close();
    }
}
