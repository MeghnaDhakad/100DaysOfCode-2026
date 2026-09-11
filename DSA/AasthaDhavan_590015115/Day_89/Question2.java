import java.util.*;
class Question2 {
    public static int buyChoco(int[] prices, int money) {
        Arrays.sort(prices);
        int cost = prices[0] + prices[1];
        if (cost <= money) {
            return money - cost;
        }
        return money;
    }
    public static void main(String[] args) {
        int[] prices = {1, 2, 2};
        int money = 3;
        System.out.println(buyChoco(prices, money));
    }
}
