class Solution {
    public int timeRequiredToBuy(int[] tickets, int k) {
        int ans = 0;
        int x = tickets[k];

        for (int i = 0; i < tickets.length; i++) {
            if (i <= k)
                ans += Math.min(tickets[i], x);
            else
                ans += Math.min(tickets[i], x - 1);
        }

        return ans;
    }
}