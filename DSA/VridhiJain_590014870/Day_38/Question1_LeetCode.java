import java.util.LinkedList;
import java.util.Queue;
class Solution {
    public int countStudents(int[] students, int[] sandwiches) {
        Queue<Integer> queue = new LinkedList<>();
        for (int i = 0; i < students.length; i++) {
            queue.add(students[i]);
        }
        int sandwich = 0;
        int count = 0;
        while (!queue.isEmpty()) {
            if (queue.peek() == sandwiches[sandwich]) {
                queue.remove();
                sandwich++;
                count = 0;
            } else {
                int student = queue.remove();
                queue.add(student);
                count++;
            }
            if (count == queue.size()) {
                break;
            }
        }
        return queue.size();
    }
}