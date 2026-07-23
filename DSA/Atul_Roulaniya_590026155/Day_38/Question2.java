import java.util.*;

public class Main {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        Deque<Integer> deck = new LinkedList<>();

        for (int i = n; i >= 1; i--) {

            if (!deck.isEmpty()) {
                int last = deck.removeLast();
                deck.addFirst(last);
            }

            deck.addFirst(i);
        }

        while (!deck.isEmpty()) {
            System.out.print(deck.removeFirst() + " ");
        }
    }
}