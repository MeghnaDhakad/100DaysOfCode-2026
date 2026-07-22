import java.util.*;

class Solution {
    public int[] deckArrangement(int n) {

        Deque<Integer> deque = new ArrayDeque<>();

        for (int card = n; card >= 1; card--) {

            if (!deque.isEmpty()) {
                deque.addFirst(deque.removeLast());
            }

            deque.addFirst(card);
        }

        int[] ans = new int[n];
        int i = 0;

        while (!deque.isEmpty()) {
            ans[i++] = deque.removeFirst();
        }

        return ans;
    }
}