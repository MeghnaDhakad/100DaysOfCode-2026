import java.util.*;
class Question2 {
    public static double fractionalKnapsack(int[] value, int[] weight, int capacity) {
        int n = value.length;
        double[][] items = new double[n][3];
        for (int i = 0; i < n; i++) {
            items[i][0] = value[i];
            items[i][1] = weight[i];
            items[i][2] = (double) value[i] / weight[i];
        }
        Arrays.sort(items, (a, b) -> Double.compare(b[2], a[2]));
        double totalValue = 0;
        for (int i = 0; i < n && capacity > 0; i++) {
            if (items[i][1] <= capacity) {
                totalValue += items[i][0];
                capacity -= (int) items[i][1];
            } else {
                totalValue += items[i][2] * capacity;
                capacity = 0;
            }
        }
        return totalValue;
    }
    public static void main(String[] args) {
        int[] value = {60, 100, 120};
        int[] weight = {10, 20, 30};
        int capacity = 50;
        System.out.println(fractionalKnapsack(value, weight, capacity));
    }
}