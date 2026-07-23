/**
 * LeetCode 1700 - Number of Students Unable to Eat Lunch
 * https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/
 */

//Need to simulate the queue until no student wants the current sandwich

import java.util.LinkedList;
import java.util.Queue;

class Solution {

    public int countStudents(int[] students, int[] sandwiches) {

        Queue<Integer> queue = new LinkedList<>();

        for (int student : students) {
            queue.offer(student);
        }

        int index = 0;
        int skipped = 0;

        while (!queue.isEmpty() && skipped < queue.size()) {

            if (queue.peek() == sandwiches[index]) {
                queue.poll();
                index++;
                skipped = 0;
            } else {
                queue.offer(queue.poll());
                skipped++;
            }
        }

        return queue.size();
    }
}