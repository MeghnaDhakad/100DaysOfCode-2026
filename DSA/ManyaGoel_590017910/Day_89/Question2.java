import java.util.*;
public class Question2 {
    public static int buyChocolates(int[] prices, int money) {
        int first = Integer.MAX_VALUE;
        int second = Integer.MAX_VALUE;

        for (int price : prices) {
            if (price < first) {
                second = first;
                first = price;
            } else if (price < second) {
                second = price;
            }
        }
        int cost = first + second;
        return cost <= money ? money - cost : money;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the number of chocolates: ");
        int n = sc.nextInt();

        int[] prices = new int[n];

        System.out.println("Enter the prices of the chocolates:");
        for (int i = 0; i < n; i++) {
            prices[i] = sc.nextInt();
        }

        System.out.print("Enter the amount of money: ");
        int money = sc.nextInt(); 

        System.out.println("Money left: " + buyChocolates(prices, money));

        sc.close();
    }
}