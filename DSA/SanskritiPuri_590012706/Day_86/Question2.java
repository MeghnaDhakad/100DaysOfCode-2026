import java.util.*;

class Solution {
    public double fractionalKnapsack(int[] value, int[] weight, int capacity) {
        int n = value.length;

        Integer[] index = new Integer[n];

        for (int i = 0; i < n; i++) {
            index[i] = i;
        }

        Arrays.sort(index, (a, b) ->
            Double.compare(
                (double) value[b] / weight[b],
                (double) value[a] / weight[a]
            )
        );

        double totalValue = 0.0;
        int remaining = capacity;

        for (int i : index) {
            if (remaining == 0) {
                break;
            }

            if (weight[i] <= remaining) {
                totalValue += value[i];
                remaining -= weight[i];
            } else {
                totalValue += (double) value[i] / weight[i] * remaining;
                remaining = 0;
            }
        }

        return totalValue;
    }
}
