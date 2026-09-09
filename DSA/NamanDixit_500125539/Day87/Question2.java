import java.util.Scanner;
import java.util.Arrays;

public class Question2 {

    // Function to find the minimum number of coins
    static int minimumCoins(int[] coins, int amount) {

        // Sort the coins from smallest to largest
        Arrays.sort(coins);

        // This variable stores the number of coins used
        int count = 0;

        // Start from the largest coin
        // coins.length - 1 means the last element
        int i = coins.length - 1;

        // Keep going while we still have an amount to make
        while (amount > 0 && i >= 0) {

            // Check if the current coin can be used
            if (coins[i] <= amount) {

                // Take the coin
                amount = amount - coins[i];

                // Increase the number of coins
                count++;

            } else {

                // The coin is too big
                // So move to the next smaller coin
                i--;
            }
        }

        // If amount is 0, we successfully made the amount
        if (amount == 0) {
            return count;
        }

        // If amount is still greater than 0,
        // it means we could not make the exact amount
        return -1;
    }

    public static void main(String[] args) {

        // Scanner is used to take input from the user
        Scanner sc = new Scanner(System.in);

        // Ask for the number of coin denominations
        System.out.print("Enter number of coins: ");
        int n = sc.nextInt();

        // Create the coins array
        int[] coins = new int[n];

        // Take coin values from the user
        System.out.println("Enter the coin denominations:");

        for (int i = 0; i < n; i++) {

            // Store each coin
            coins[i] = sc.nextInt();
        }

        // Ask for the target amount
        System.out.print("Enter the amount: ");
        int amount = sc.nextInt();

        // Find the minimum number of coins
        int result = minimumCoins(coins, amount);

        // Print the answer
        if (result == -1) {
            System.out.println("The amount cannot be made with these coins.");
        } else {
            System.out.println("Minimum number of coins = " + result);
        }

        // Close Scanner
        sc.close();
    }
}