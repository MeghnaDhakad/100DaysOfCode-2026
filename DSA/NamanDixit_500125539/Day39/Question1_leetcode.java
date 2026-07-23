
import java.util.LinkedList;
import java.util.Queue;

class Question1_leetcode {

    static class Person {

        int index;
        int tickets;

        Person(int index, int tickets) {
            this.index = index;
            this.tickets = tickets;
        }
    }

    public int timeRequiredToBuy(int[] tickets, int k) {

        Queue<Person> queue = new LinkedList<>();

        // Add all people into queue
        for (int i = 0; i < tickets.length; i++) {
            queue.offer(new Person(i, tickets[i]));
        }

        int time = 0;

        while (!queue.isEmpty()) {

            Person current = queue.poll();

            // Buy one ticket
            current.tickets--;

            time++;

            // Target person finished
            if (current.index == k && current.tickets == 0) {
                return time;
            }

            // Move to back if tickets remain
            if (current.tickets > 0) {
                queue.offer(current);
            }
        }

        return time;
    }
}
