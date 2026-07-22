import java.util.*;

public class Question2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        int[] ans = new int[n];
        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < n; i++) q.add(i);
        for (int i = 1; i <= n; i++) {
            ans[q.poll()] = i;
            if (!q.isEmpty()) q.add(q.poll());
        }

        System.out.print(Arrays.toString(ans));
    }
}