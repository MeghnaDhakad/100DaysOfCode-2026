import java.util.*;

class Solution {
    public double fractionalKnapsack(int[] value, int[] weight, int capacity) {
        
        int n = value.length;

        double[][] items = new double[n][3];

        for (int i = 0; i < n; i++) {
            items[i][0] = value[i];
            items[i][1] = weight[i];
            items[i][2] = (double) value[i] / weight[i];
        }

        Arrays.sort(items, (a, b) -> Double.compare(b[2], a[2]));

        double ans = 0.0;
        int remaining = capacity;

        for (int i = 0; i < n && remaining > 0; i++) {

            if (items[i][1] <= remaining) {

                ans += items[i][0];
                remaining -= (int) items[i][1];
            } else {
                ans += items[i][2] * remaining;
                remaining = 0;
            }
        }

        return ans;
    }
}