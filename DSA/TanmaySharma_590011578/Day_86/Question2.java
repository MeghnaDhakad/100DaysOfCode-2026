import java.util.*;

public class Question2 {

    static class Item {
        int value;
        int weight;

        Item(int value, int weight) {
            this.value = value;
            this.weight = weight;
        }
    }

    static double fractionalKnapsack(Item[] items, int capacity) {
        Arrays.sort(items, (a, b) ->
                Double.compare((double) b.value / b.weight,
                               (double) a.value / a.weight));

        double totalValue = 0;

        for (Item item : items) {
            if (capacity >= item.weight) {
                capacity -= item.weight;
                totalValue += item.value;
            } else {
                totalValue += ((double) item.value / item.weight) * capacity;
                break;
            }
        }

        return totalValue;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        Item[] items = new Item[n];

        for (int i = 0; i < n; i++) {
            int value = sc.nextInt();
            int weight = sc.nextInt();
            items[i] = new Item(value, weight);
        }

        int capacity = sc.nextInt();

        System.out.println(fractionalKnapsack(items, capacity));
        sc.close();
    }
}