class Solution {
    public int coinChange(int[] coins, int amount) {
        Arrays.sort(coins);
        int result = 0;

        for (int i = coins.length-1 ; i >=0 ; i-- ) {
            if (amount == 0 ) {
                return result;
            }

            while (amount >= coins[i]) {
                result++;
                amount-=coins[i];
            }

        }
        if (amount > 0) {
            return -1;
        }
        return result;
    }
}