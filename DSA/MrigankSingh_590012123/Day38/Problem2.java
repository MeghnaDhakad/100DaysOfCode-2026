import java.util.ArrayDeque;
import java.util.Deque;

public class Problem2 {
    public int[] cardTrick(int n) {
        Deque<Integer> deque = new ArrayDeque<>();

        for (int card = n; card >= 1; card--) {
            if (!deque.isEmpty()) {
                deque.addFirst(deque.removeLast());
            }
            deque.addFirst(card);
        }

        int[] result = new int[n];
        int index = 0;
        while (!deque.isEmpty()) {
            result[index++] = deque.removeFirst();
        }

        return result;
    }
}