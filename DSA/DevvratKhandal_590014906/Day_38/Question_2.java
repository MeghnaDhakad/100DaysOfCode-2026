import java.util.*;

public class Question_2 {

    public static int[] cardTrick(int n) {

        Deque<Integer> deck = new LinkedList<>();

        for (int card = n; card >= 1; card--) {

            if (!deck.isEmpty()) {
                int last = deck.removeLast();
                deck.addFirst(last);
            }

            deck.addFirst(card);
        }

        int[] result = new int[n];
        int i = 0;

        for (int card : deck) {
            result[i++] = card;
        }

        return result;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of cards: ");
        int n = sc.nextInt();

        int[] result = cardTrick(n);

        System.out.println("Initial arrangement of deck:");

        System.out.print("[");
        for (int i = 0; i < result.length; i++) {
            System.out.print(result[i]);

            if (i < result.length - 1) {
                System.out.print(", ");
            }
        }
        System.out.println("]");

        sc.close();
    }
}