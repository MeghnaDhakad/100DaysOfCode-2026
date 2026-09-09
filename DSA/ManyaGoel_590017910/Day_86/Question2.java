import java.util.*;
public class Question2 {
    public static class Item {
        long value, weight;
        Item(long value, long weight) {
            this.value = value;
            this.weight = weight;
        }
    }

    public static double knapsack(Item[] items, long capacity) {
        Arrays.sort(items, (a, b) -> Long.compare(b.value * a.weight, a.value * b.weight));
        double total = 0;
        for (Item item : items) {
            if (capacity == 0) break;
            if (item.weight <= capacity) {
                total += item.value;
                capacity -= item.weight;
            } else {
                total += (double) item.value * capacity / item.weight;
                break;
            }
        }
        return total;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of items: ");
        int n = sc.nextInt();
        long[] values = new long[n], weights = new long[n];

        System.out.println("Enter the values of the items:");
        for (int i = 0; i < n; i++) values[i] = sc.nextLong();

        System.out.println("Enter the weights of the items:");
        for (int i = 0; i < n; i++) weights[i] = sc.nextLong();

        System.out.print("Enter the knapsack capacity: ");
        long capacity = sc.nextLong();

        Item[] items = new Item[n];
        for (int i = 0; i < n; i++) items[i] = new Item(values[i], weights[i]);

        double answer = knapsack(items, capacity);
        System.out.println("Maximum value = " + (answer == (long) answer ? (long) answer : answer));
        sc.close();
    }
}