import java.util.ArrayDeque;
import java.util.Deque;

class Solution {
    public int timeRequiredToBuy(int[] tickets, int k) {
        Deque<int[]> queue = new ArrayDeque<>(); // {index, ticketsRemaining}
        for (int i = 0; i < tickets.length; i++) {
            queue.addLast(new int[]{i, tickets[i]});
        }

        int time = 0;

        while (!queue.isEmpty()) {
            int[] person = queue.pollFirst();
            person[1]--; // buy one ticket
            time++;

            if (person[1] == 0) {
                if (person[0] == k) {
                    return time;
                }
                // else: this person is done, leaves the line (not re-added)
            } else {
                queue.addLast(person); // still needs more tickets, go to back
            }
        }

        return time; // fallback, shouldn't be reached if k is valid
    }
}
