import java.util.Arrays;

public class Fractional_Knapsack {

    public static double fractionalKnapsack(int capacity, int[] weights, int[] values) {
        int n = weights.length;
        double[][] items = new double[n][2];

        for (int i = 0; i < n; i++) {
            items[i][0] = values[i];
            items[i][1] = weights[i];
        }

        // Sort items by value-to-weight ratio in descending order
        Arrays.sort(items, (a, b) -> Double.compare(b[0] / b[1], a[0] / a[1]));

        double totalValue = 0.0;

        for (int i = 0; i < n; i++) {
            if (capacity == 0) {
                break;
            }

            if (items[i][1] <= capacity) {
                totalValue += items[i][0];
                capacity -= items[i][1];
            } else {
                totalValue += items[i][0] * ((double) capacity / items[i][1]);
                capacity = 0;
            }
        }

        return totalValue;
    }

    public static void main(String[] args) {
        int[] weights = {10, 20, 30};
        int[] values = {60, 100, 120};
        int capacity = 50;

        double maxValue = fractionalKnapsack(capacity, weights, values);
        System.out.println("Maximum value in Knapsack = " + maxValue);
    }
    
}