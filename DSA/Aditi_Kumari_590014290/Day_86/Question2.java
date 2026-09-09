package DSA.Aditi_Kumari_590014290.Day_86;

import java.util.*;

public class Question2 {
    public static double fractionalKnapsack(int[] value, int[] weight, int capacity) {
        int n = value.length;
        double[][] items = new double[n][2];

        for (int i = 0; i < n; i++) {
            items[i][0] = value[i];
            items[i][1] = weight[i];
        }

        Arrays.sort(items, (a, b) -> Double.compare(b[0] / b[1], a[0] / a[1]));

        double totalValue = 0;

        for (int i = 0; i < n; i++) {
            if (capacity >= items[i][1]) {
                totalValue += items[i][0];
                capacity -= (int) items[i][1];
            } else {
                totalValue += (items[i][0] / items[i][1]) * capacity;
                break;
            }
        }

        return totalValue;
    }
}