public class BuyTwoChocolates {

    public static int buyChoco(int[] prices, int money) {

        int cheapest = Integer.MAX_VALUE;
        int secondCheapest = Integer.MAX_VALUE;

        for (int price : prices) {

            if (price < cheapest) {
                secondCheapest = cheapest;
                cheapest = price;
            } 
            else if (price < secondCheapest) {
                secondCheapest = price;
            }
        }

        int total = cheapest + secondCheapest;

        if (total <= money) {
            return money - total;
        }

        return money;
    }

    public static void main(String[] args) {

        int[] prices = {1, 2, 2};
        int money = 3;

        int result = buyChoco(prices, money);

        System.out.println(result);
    }
}