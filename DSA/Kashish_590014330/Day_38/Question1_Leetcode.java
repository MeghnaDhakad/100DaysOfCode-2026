import java.util.ArrayDeque;
import java.util.Deque;

public class Question1_Leetcode{

    public static int countStudents(int[] students, int[] sandwiches) {
        Deque<Integer> q = new ArrayDeque<>();
        for (int student : students) {
            q.offer(student);
        }

        int lastEatenTracker = 0;

        for (int sandwich : sandwiches) {
            while (!q.isEmpty()) {
                if (lastEatenTracker == q.size()) {
                    return q.size();
                }

                if (q.peek() == sandwich) {
                    q.poll();
                    lastEatenTracker = 0;
                    break;
                } else {
                    q.offer(q.poll());
                    lastEatenTracker++;
                }
            }
        }

        return q.size();
    }
}