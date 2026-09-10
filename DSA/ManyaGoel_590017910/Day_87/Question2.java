import java.util.*;

public class Question2 {
    static int minCoins(int[] coins, int amount) {
        Arrays.sort(coins);
        int count = 0;

        for (int i = coins.length - 1; i >= 0 && amount > 0; i--) {
            count += amount / coins[i];
            amount %= coins[i];
        }
        return amount == 0 ? count : -1;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the number of coin denominations: ");
        int n = sc.nextInt();

        int[] coins = new int[n];
        System.out.println("Enter the coin denominations:");

        for (int i = 0; i < n; i++)
            coins[i] = sc.nextInt();

        System.out.print("Enter the target amount: ");
        int amount = sc.nextInt();

        System.out.println("Minimum number of coins: " + minCoins(coins, amount));

        sc.close();
    }
}