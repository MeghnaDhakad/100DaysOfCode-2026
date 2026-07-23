package Day_38;

import java.util.*;

public class d37question2_technical {
public static int[] cardTrick(int n) {
        Deque<Integer> deque = new LinkedList<>();

        for (int i = n; i >= 1; i--) {
            if (!deque.isEmpty()) {
                // Reverse of moving top card to bottom:
                // move last card to the front
                deque.addFirst(deque.removeLast());
            }
            // Place current card at the top
            deque.addFirst(i);
        }

        int[] result = new int[n];
        int index = 0;

        while (!deque.isEmpty()) {
            result[index++] = deque.removeFirst();
        }

        return result;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        System.out.println(cardTrick(n));
        sc.close();
    }}