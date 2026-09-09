import java.util.*;

class Solution {
    public double fractionalKnapsack(int[] val, int[] wt, int capacity) {
        int n = val.length;

        Integer[] index = new Integer[n];

        for (int i = 0; i < n; i++) {
            index[i] = i;
        }

        Arrays.sort(index, (a, b) -> 
            Double.compare((double) val[b] / wt[b], (double) val[a] / wt[a])
        );

        double totalValue = 0;

        for (int i : index) {
            if (capacity >= wt[i]) {
                capacity -= wt[i];
                totalValue += val[i];
            } else {
                totalValue += ((double) val[i] / wt[i]) * capacity;
                break;
            }
        }

        return totalValue;
    }
}
