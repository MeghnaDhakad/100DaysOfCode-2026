
import java.util.*;
class FK{
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
            int[] value,
            int[] weight,
            int capacity) {
        int n = value.length;
        Item[] items = new Item[n];
        for (int i = 0; i < n; i++) {
            items[i] = new Item(value[i], weight[i]);
        }
        Arrays.sort(items, (a, b) ->
                Double.compare(b.ratio, a.ratio));

        double totalValue = 0;
        for (Item item : items) {
            if (capacity >= item.weight) {
                capacity -= item.weight;
                totalValue += item.value;
            } else {
                totalValue += item.ratio * capacity;
                capacity = 0;
                break;
            }
        }
        return totalValue;
    }
    public static void main(String[] args) {
        int[] value = {60, 100, 120};
        int[] weight = {10, 20, 30};
        int capacity = 50;
        double answer =
                fractionalKnapsack(value, weight, capacity);
                System.out.println("Maximum value:" + answer);
    }
}