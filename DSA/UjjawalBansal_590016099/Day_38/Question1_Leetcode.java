import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Queue;

public class Question1_Leetcode {
    // This is the method by using queue and stack. Queue storing the students and stack storing the sandwiches. It takes O(n^2) time and O(n) space.
    public int countStudents(int[] students, int[] sandwiches) {
        Queue<Integer> q = new ArrayDeque<>();
        Deque<Integer> stack = new ArrayDeque<>();

        for (int i = 0; i < students.length; i++) {
            q.offer(students[i]);
        }

        for (int j = sandwiches.length - 1; j >= 0; j--) {
            stack.push(sandwiches[j]);
        }

        int remaining = q.size(), current = 0;

        while (!stack.isEmpty() && remaining != current) {
            if (stack.peek() == q.peek()) {
                q.poll();
                stack.pop();
                remaining--;
                current = 0;
            }
            else {
                q.offer(q.poll());
                current++;
            }
        }
        return stack.size();
    }


    // 
    public int countStudentsOptimized(int[] students, int[] sandwiches) {
        int[] arr = new int[2];

        for (int student : students) {
            arr[student]++;
        }

        for (int sandwich : sandwiches) {
            if (arr[sandwich] == 0) {
                return arr[1-sandwich];
            }
            arr[sandwich]--;
        }
        return 0;
    }
}