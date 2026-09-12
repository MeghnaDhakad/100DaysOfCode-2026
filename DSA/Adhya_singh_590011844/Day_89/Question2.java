import java.util.*;

public class Main {

    static int buyChoco(int[] prices, int money) {
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

        if (cost <= money) {
            return money - cost;
        }

        return money;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int[] prices = new int[n];

        for (int i = 0; i < n; i++) {
            prices[i] = sc.nextInt();
        }

        int money = sc.nextInt();

        System.out.println(buyChoco(prices, money));

        sc.close();
    }
}