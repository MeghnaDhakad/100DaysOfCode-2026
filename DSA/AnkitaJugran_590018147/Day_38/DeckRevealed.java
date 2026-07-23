import java.util.LinkedList;
import java.util.Queue;
import java.util.Arrays;

public class DeckRevealed {

    public static int[] deckRevealedIncreasing(int n) {
        
        Queue<Integer> positions = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            positions.add(i);
        }

        int[] revealOrder = new int[n]; // revealOrder[k] = position revealed at step k
        int idx = 0;

        while (!positions.isEmpty()) {
            // Reveal front position
            revealOrder[idx++] = positions.poll();

            // Move next position to the back (if any remain)
            if (!positions.isEmpty()) {
                positions.add(positions.poll());
            }
        }

        // Assign values 1..n to positions in the order they were revealed
        int[] result = new int[n];
        for (int k = 0; k < n; k++) {
            result[revealOrder[k]] = k + 1;
        }

        return result;
    }

    public static void main(String[] args) {
        int[] testCases = {4, 3, 5};

        for (int n : testCases) {
            int[] answer = deckRevealedIncreasing(n);
            System.out.println("n = " + n + " -> " + Arrays.toString(answer));
        }
    }
}