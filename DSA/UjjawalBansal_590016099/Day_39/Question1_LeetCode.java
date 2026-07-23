import java.util.ArrayDeque;
import java.util.Queue;

public class Question1_LeetCode {
    // This is the Queue Simulation method. It takes O(n * tickets[k]) time and O(n) space.
    public static int timeRequiredToBuyQueue(int[] tickets, int k) {
        Queue<Integer> q = new ArrayDeque<>();
        
        for (int i = 0; i < tickets.length; i++) {
            q.offer(i);
        }
        
        int time = 0;
        
        while (!q.isEmpty()) {
            time++;
            int temp = q.poll();
            
            tickets[temp]--;
            
            if (temp == k && tickets[temp] == 0) {
                return time;
            }
            
            if (tickets[temp] > 0) {
                q.offer(temp);
            }
        }
        
        return time;
    }

    // This is the Optimized method without using any queue and by just tracing the array. It takes O(n) time and O(1) space.
    public static int timeRequiredToBuyOptimized(int[] tickets, int k) {
        int sum = 0;
        for (int i = 0; i < tickets.length; i++) {
            if (i <= k) {
                sum += Math.min(tickets[k], tickets[i]);
            } 
            else {
                sum += Math.min(tickets[k] - 1, tickets[i]);
            }
        }
        return sum;
    }
}
