import java.util.*;

class Solution {

    static class Item {
        int value;
        int weight;
        double ratio;

        Item(int value, int weight) {
            this.value = value;
            this.weight = weight;
            this.ratio = (double) value / weight;
        }
    }

    public static double fractionalKnapsack(
            int n, int[] value, int[] weight, int capacity) {

        Item[] items = new Item[n];

        // Create items with value/weight ratio
        for (int i = 0; i < n; i++) {
            items[i] = new Item(value[i], weight[i]);
        }

        // Sort by highest value/weight ratio
        Arrays.sort(items, (a, b) ->
                Double.compare(b.ratio, a.ratio));

        double totalValue = 0.0;
        int remainingCapacity = capacity;

        for (Item item : items) {

            // Take the complete item
            if (item.weight <= remainingCapacity) {
                totalValue += item.value;
                remainingCapacity -= item.weight;
            }

            // Take fraction of the item
            else {
                totalValue += item.ratio * remainingCapacity;
                break;
            }
        }

        return totalValue;
    }

    public static void main(String[] args) {

        int n = 3;

        int[] value = {60, 100, 120};
        int[] weight = {10, 20, 30};

        int capacity = 50;

        double answer = fractionalKnapsack(
                n, value, weight, capacity);

        System.out.println(answer);
    }
}
