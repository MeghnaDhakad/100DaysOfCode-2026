import java.util.*;

public class Main {

    public static int minCoins(int[] coins, int amount) {

        // Sort coins in ascending order
        Arrays.sort(coins);

        int count = 0;

        // Start from the largest coin
        for (int i = coins.length - 1; i >= 0; i--) {

            // Use the largest possible coin
            while (amount >= coins[i]) {
                amount -= coins[i];
                count++;
            }
        }

        // If amount is still left, it cannot be formed
        if (amount != 0) {
            return -1;
        }

        return count;
    }

    public static void main(String[] args) {

        int n = 5;
        int[] coins = {1, 5, 10, 25, 50};
        int amount = 87;

        System.out.println(minCoins(coins, amount));
    }
}