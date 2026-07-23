import java.util.Arrays;
import java.util.PriorityQueue;
public class Question2 {
    public int minConferenceRooms(int[][] a) {
        Arrays.sort(a, (x, y) -> x[0] - y[0]);
        PriorityQueue<Integer> p = new PriorityQueue<>();
        for (int[] i : a) {
            if (!p.isEmpty() && p.peek() <= i[0]) p.poll();
            p.offer(i[1]);
        } return p.size();
    }
}