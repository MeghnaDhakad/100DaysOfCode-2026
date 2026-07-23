
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Question2 {

    // Function to construct the initial deck
    public static int[] cardTrick(int n) {

        // Queue to store positions
        Queue<Integer> queue = new LinkedList<>();

        // Result array
        int[] deck = new int[n];

        // Add all positions into the queue
        for (int i = 0; i < n; i++) {
            queue.offer(i);
        }

        // Place cards from 1 to n
        for (int card = 1; card <= n; card++) {

            // Get the front position
            int position = queue.poll();

            // Place current card at this position
            deck[position] = card;

            // Move next position to the back
            if (!queue.isEmpty()) {
                queue.offer(queue.poll());
            }
        }

        // Return the deck arrangement
        return deck;
    }

    public static void main(String[] args) {

        // Create Scanner object
        Scanner sc = new Scanner(System.in);

        // Input n
        System.out.print("Enter number of cards: ");
        int n = sc.nextInt();

        // Get initial arrangement
        int[] result = cardTrick(n);

        // Print the initial deck
        System.out.println("Initial Deck Arrangement:");

        for (int i = 0; i < result.length; i++) {
            System.out.print(result[i] + " ");
        }

        sc.close();
    }
}
