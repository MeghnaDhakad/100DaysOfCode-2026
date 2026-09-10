import java.util.Scanner;

public class Question2 {
    public static int minimumNumberOfCoins(int[] denominations, int amount) {
        int i = denominations.length - 1;
        int count = 0;
        while (amount > 0 && i >= 0) {
            count += amount/denominations[i];
            amount %= denominations[i];
            i--;
        }
        if (amount > 0) return -1;
        else return count;
    }

    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter the number of different coins denominations: ");
        int n = sc.nextInt();

        System.out.println("Enter the different coins denomination values: ");
        int[] denominations = new int[n];
        for (int i = 0; i < n; i++) {
            denominations[i] = sc.nextInt();
        }

        System.out.println("Enter the required amount: ");
        int amount = sc.nextInt();

        int ans = minimumNumberOfCoins(denominations, amount);
        System.out.println("Minimum coins required for the given amount: " + ans);
        sc.close();
    }
}
