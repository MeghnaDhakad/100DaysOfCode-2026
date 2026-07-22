import java.util.*;

class Solution {
    public int countStudents(int[] students, int[] sandwiches) {

        Queue<Integer> studentQueue = new LinkedList<>();
        Queue<Integer> sandwichQueue = new LinkedList<>();

        for (int student : students) {
            studentQueue.offer(student);
        }

        for (int sandwich : sandwiches) {
            sandwichQueue.offer(sandwich);
        }

        int rotations = 0;

        while (!studentQueue.isEmpty()) {

            if (studentQueue.peek().equals(sandwichQueue.peek())) {
                studentQueue.poll();
                sandwichQueue.poll();
                rotations = 0; 
            } else {
                studentQueue.offer(studentQueue.poll());
                rotations++;
            }

            if (rotations == studentQueue.size()) {
                break;
            }
        }

        return studentQueue.size();
    }
}