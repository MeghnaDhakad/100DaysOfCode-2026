import java.util.Scanner;

public class Question2 {
    public static int buyTwoChocolates(int[] prices, int money) {
        int min1 = Math.min(prices[0], prices[1]);
        int min2 = Math.max(prices[0], prices[1]);

        for (int i = 2; i < prices.length; i++) {
            if (prices[i] < min1) {
                min2 = min1;
                min1 = prices[i];
            }
            else if (prices[i] < min2) {
                min2 = prices[i];
            }
        }

        if (min2 + min1 > money) return money;
        else return money - (min2 + min1);  
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        System.out.print("Enter the number of elements in prices array: ");
        int n = sc.nextInt();
        
        int[] prices = new int[n];
        System.out.print("Enter the prices: ");
        for (int i = 0; i < n; i++) {
            prices[i] = sc.nextInt();
        }
        
        System.out.print("Enter the money: ");
        int money = sc.nextInt();

        int ans = buyTwoChocolates(prices, money);

        System.out.println("Leftover Money: " + ans);
        sc.close();
    }
}
