import java.util.*;

public class Question2 {

    public static int minCoins(long[] coins, long amount) {
        Arrays.sort(coins);

        int count = 0;

        for (int i = coins.length - 1; i >= 0; i--) {
            if (coins[i] <= amount) {
                count += amount / coins[i];
                amount %= coins[i];
            }

            if (amount == 0) {
                break;
            }
        }

        return amount == 0 ? count : -1;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        long[] coins = new long[n];

        for (int i = 0; i < n; i++) {
            coins[i] = sc.nextLong();
        }

        long amount = sc.nextLong();

        System.out.println(minCoins(coins, amount));

        sc.close();
    }
}