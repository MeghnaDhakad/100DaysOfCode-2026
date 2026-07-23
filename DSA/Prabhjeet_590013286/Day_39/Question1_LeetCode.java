/**
 * LeetCode 2073 - Time Needed to Buy Tickets
 * https://leetcode.com/problems/time-needed-to-buy-tickets/
 */

//Need to count how many seconds each person contributes

class Solution {

    public int timeRequiredToBuy(int[] tickets, int k) {

        int time = 0;

        for (int i = 0; i < tickets.length; i++) {

            // people before or at k can buy at most tickets[k] times
            if (i <= k) {
                time += Math.min(tickets[i], tickets[k]);
            }
            // people after k stop one turn earlier
            else {
                time += Math.min(tickets[i], tickets[k] - 1);
            }
        }

        return time;
    }
}