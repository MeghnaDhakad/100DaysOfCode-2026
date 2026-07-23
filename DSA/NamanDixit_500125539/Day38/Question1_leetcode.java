
import java.util.LinkedList;
import java.util.Queue;

class Question1_leetcode {

    public int countStudents(int[] students, int[] sandwiches) {

        Queue<Integer> queue = new LinkedList<>();

        // Add students into queue
        for (int student : students) {
            queue.offer(student);
        }

        int sandwichIndex = 0;
        int count = 0;

        while (!queue.isEmpty()) {

            // Nobody wants current sandwich
            if (count == queue.size()) {
                break;
            }

            int student = queue.poll();

            // Student eats sandwich
            if (student == sandwiches[sandwichIndex]) {

                sandwichIndex++;

                // Reset refusal count
                count = 0;
            } // Move student to back
            else {

                queue.offer(student);

                count++;
            }
        }

        return queue.size();
    }
}
