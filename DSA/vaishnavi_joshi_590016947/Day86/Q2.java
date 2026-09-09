import java.util.*;

class Solution {

    static class Item {
        long value;
        long weight;
        double ratio;

        Item(long value, long weight) {
            this.value = value;
            this.weight = weight;
            this.ratio = (double) value / weight;
        }
    }

    public static double fractionalKnapsack(
            int n, long[] value, long[] weight, long capacity) {

        Item[] items = new Item[n];

        // Create items
        for (int i = 0; i < n; i++) {
            items[i] = new Item(value[i], weight[i]);
        }

        // Sort by value/weight ratio in descending order
        Arrays.sort(items, (a, b) ->
                Double.compare(b.ratio, a.ratio));

        double totalValue = 0.0;
        long remainingCapacity = capacity;

        for (Item item : items) {

            if (remainingCapacity == 0) {
                break;
            }

            // Take complete item
            if (item.weight <= remainingCapacity) {

                totalValue += item.value;
                remainingCapacity -= item.weight;

            } 
            // Take fractional part
            else {

                totalValue += item.ratio * remainingCapacity;
                remainingCapacity = 0;
            }
        }

        return totalValue;
    }
}