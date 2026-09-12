
class TC{
    public static int buyChoco(int[] prices, int money){
        int first = Integer.MAX_VALUE;
        int second = Integer.MAX_VALUE;
        for (int price : prices) {
            if (price < first) {
                second = first;
                first = price;
            }
            else if (price < second) {
                second = price;
            }
        }
        int total = first + second;
        if (total <= money) {
            return money - total;
        }
        return money;
    }
    public static void main(String[] args){
        int[] prices = {1, 2, 2};
        int money = 3;
        int answer = buyChoco(prices, money);
        System.out.println("Money left:" + answer);
    }
}