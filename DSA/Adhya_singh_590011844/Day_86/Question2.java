import java.util.*;

public class Main {

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

    static double fractionalKnapsack(long[] value, long[] weight, long capacity) {
        int n = value.length;
        Item[] items = new Item[n];

        for (int i = 0; i < n; i++) {
            items[i] = new Item(value[i], weight[i]);
        }

        Arrays.sort(items, (a, b) -> Double.compare(b.ratio, a.ratio));

        double totalValue = 0.0;
        long remaining = capacity;

        for (Item item : items) {
            if (remaining == 0) {
                break;
            }

            if (item.weight <= remaining) {
                
                totalValue += item.value;
                remaining -= item.weight;
            } else {
                totalValue += item.ratio * remaining;
                remaining = 0;
            }
        }

        return totalValue;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        long[] value = new long[n];
        long[] weight = new long[n];

        for (int i = 0; i < n; i++) {
            value[i] = sc.nextLong();
        }

        for (int i = 0; i < n; i++) {
            weight[i] = sc.nextLong();
        }

        long capacity = sc.nextLong();

        double result = fractionalKnapsack(value, weight, capacity);

        System.out.printf("%.6f%n", result);

        sc.close();
    }
}