import java.util.*;

public class Question2 {

    static int minimumCoins(int[] coins, int amount) {
        Arrays.sort(coins);

        int count = 0;

        for (int i = coins.length - 1; i >= 0; i--) {
            if (coins[i] <= amount) {
                count += amount / coins[i];
                amount %= coins[i];
            }

            if (amount == 0)
                return count;
        }

        return -1;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        int[] coins = new int[n];

        for (int i = 0; i < n; i++) {
            coins[i] = sc.nextInt();
        }

        int amount = sc.nextInt();

        System.out.println(minimumCoins(coins, amount));

        sc.close();
    }
}