import java.util.Scanner;
import java.util.Arrays;

public class Question2 {

    // This class stores the value and weight of an item
    static class Item {

        // Value of the item
        int value;

        // Weight of the item
        int weight;

        // Constructor
        Item(int value, int weight) {
            this.value = value;
            this.weight = weight;
        }
    }

    // Function to calculate maximum value
    static double fractionalKnapsack(int[] value, int[] weight, int capacity) {

        // Number of items
        int n = value.length;

        // Create an array of Items
        Item[] items = new Item[n];

        // Store value and weight together
        for (int i = 0; i < n; i++) {
            items[i] = new Item(value[i], weight[i]);
        }

        // Sort items according to value/weight ratio
        //
        // Item with higher ratio comes first
        Arrays.sort(items, (a, b) -> {

            // Calculate value per weight for both items
            double ratioA = (double) a.value / a.weight;
            double ratioB = (double) b.value / b.weight;

            // Higher ratio should come first
            return Double.compare(ratioB, ratioA);
        });

        // This stores the total value we collect
        double totalValue = 0;

        // Go through every item
        for (int i = 0; i < n; i++) {

            // If the entire item can fit
            if (items[i].weight <= capacity) {

                // Take the entire item
                totalValue = totalValue + items[i].value;

                // Reduce the remaining capacity
                capacity = capacity - items[i].weight;

            } else {

                // The complete item cannot fit
                //
                // So we take only the fraction
                // that can fit inside the remaining capacity.

                totalValue = totalValue
                        + ((double) items[i].value / items[i].weight) * capacity;

                // The knapsack is now full
                capacity = 0;

                // No more items can be added
                break;
            }
        }

        // Return the maximum value
        return totalValue;
    }

    public static void main(String[] args) {

        // Scanner is used to take input from the user
        Scanner sc = new Scanner(System.in);

        // Take number of items
        System.out.print("Enter number of items: ");
        int n = sc.nextInt();

        // Create value array
        int[] value = new int[n];

        // Create weight array
        int[] weight = new int[n];

        // Take values from the user
        System.out.println("Enter the values:");

        for (int i = 0; i < n; i++) {
            value[i] = sc.nextInt();
        }

        // Take weights from the user
        System.out.println("Enter the weights:");

        for (int i = 0; i < n; i++) {
            weight[i] = sc.nextInt();
        }

        // Take knapsack capacity
        System.out.print("Enter knapsack capacity: ");
        int capacity = sc.nextInt();

        // Find maximum value
        double result = fractionalKnapsack(value, weight, capacity);

        // Print the answer
        System.out.println("Maximum value = " + result);

        // Close Scanner
        sc.close();
    }
}