import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Queue;
import java.util.Scanner;

public class Question2 {
    public static int[] cardTrick(int n) {
        if (n <= 0) return new int[0];
        
        Queue<Integer> q = new ArrayDeque<>();
        for (int i = 0; i < n; i++) {
            q.offer(i);
        }
        
        int[] result = new int[n];
        for (int i = 1; i <= n; i++) {
            result[q.poll()] = i;
            if (!q.isEmpty()) {
                q.offer(q.poll());
            }
        }
        return result;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter total number of cards: ");
        int n = sc.nextInt();
        int[] arr = cardTrick(n);

        System.out.println("Initial Arrangement that reveals card in increasing order: ");
        System.out.println(Arrays.toString(arr));
        sc.close();
    }
}