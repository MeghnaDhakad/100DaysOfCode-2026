import java.util.*;

public class MinimumCoins {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        // Number of coins
        int n = sc.nextInt();

        int[] coins = new int[n];

        // Input coin denominations
        for (int i = 0; i < n; i++) {
            coins[i] = sc.nextInt();
        }

        // Target amount
        int amount = sc.nextInt();

        // Sort coins
        Arrays.sort(coins);

        int count = 0;

        // Start with the largest coin
        for (int i = n - 1; i >= 0; i--) {

            while (amount >= coins[i]) {
                amount -= coins[i];
                count++;
            }
        }

        System.out.println(count);

        sc.close();
    }
}