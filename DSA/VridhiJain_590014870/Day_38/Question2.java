import java.util.LinkedList;
import java.util.Queue;
public class Question2 {
    public static void main(String[] args) {
        int n = 4;
        int[] deck = new int[n];
        Queue<Integer> positions = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            positions.add(i);
        }
        for (int card = 1; card <= n; card++) {
            int position = positions.remove();
            deck[position] = card;
            if (!positions.isEmpty()) {
                int next = positions.remove();
                positions.add(next);
            }
        }
        for (int i = 0; i < n; i++) {
            System.out.print(deck[i] + " ");
        }
    }
}