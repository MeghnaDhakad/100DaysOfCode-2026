import java.util.*;

class Solution {
    public int minCoins(int[] coins, int amount) {
        // Sort denominations in descending order
        Integer[] sortedCoins = Arrays.stream(coins).boxed().toArray(Integer[]::new);
        Arrays.sort(sortedCoins, Collections.reverseOrder());
        
        int count = 0;
        int remaining = amount;
        
        for (int coin : sortedCoins) {
            if (remaining <= 0) break;
            if (coin <= remaining) {
                count += remaining / coin;
                remaining %= coin;
            }
        }
        
        return remaining == 0 ? count : -1; // -1 if amount can't be made exactly
    }
    
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] coins = {1, 5, 10, 25, 50};
        int amount = 87;
        System.out.println(sol.minCoins(coins, amount)); // Output: 5
    }
}
