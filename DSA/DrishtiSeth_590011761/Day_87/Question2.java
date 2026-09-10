import java.util.*;

class Solution {
    public static int minCoins(int[] coins, int amount) {

        // Sort coins in ascending order
        Arrays.sort(coins);

        int count = 0;

        // Start from the largest coin
        for (int i = coins.length - 1; i >= 0; i--) {

            if (coins[i] <= amount) {
                count += amount / coins[i];
                amount = amount % coins[i];
            }
        }

        // If amount is still left, it cannot be formed
        if (amount != 0) {
            return -1;
        }

        return count;
    }

    public static void main(String[] args) {

        int[] coins = {1, 5, 10, 25, 50};
        int amount = 87;

        System.out.println(minCoins(coins, amount));
    }
}
