import java.util.*;
class Question2 {
    public static int minCoins(int[] coins, int amount) {
        Arrays.sort(coins);
        int count = 0;
        for (int i = coins.length - 1; i >= 0; i--) {

            while (amount >= coins[i]) {
                amount -= coins[i];
                count++;
            }
        }
        return count;
    }

    public static void main(String[] args) {
        int[] coins = {1, 5, 10, 25, 50};
        int amount = 87;
        System.out.println(minCoins(coins, amount));
    }
}