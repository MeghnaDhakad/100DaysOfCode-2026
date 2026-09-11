package Day_88;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;

public class question2 {
    public static void main(String[] args) {
        int[] deadline = {4, 1, 1, 1};
        int[] profit = {20, 10, 40, 30};

        Integer[] indices = new Integer[profit.length];
        for (int i = 0; i < profit.length; i++) indices[i] = i;
        Arrays.sort(indices, (a, b) -> profit[b] - profit[a]);

        boolean[] slots = new boolean[5];
        int totalProfit = 0;

        for (int idx : indices) {
            for (int t = deadline[idx]; t > 0; t--) {
                if (!slots[t]) {
                    slots[t] = true;
                    totalProfit += profit[idx];
                    break;
                }
            }
        }

        System.out.println(totalProfit); 
    }
}
