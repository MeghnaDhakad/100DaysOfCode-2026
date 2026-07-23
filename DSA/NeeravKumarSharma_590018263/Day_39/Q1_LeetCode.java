class Solution {
    public int timeRequiredToBuy(int[] tickets, int k) {
        int totalTime = 0;
        int targetTickets = tickets[k];
        
        for (int i = 0; i < tickets.length; i++) {
            if (i <= k) {
                totalTime += Math.min(tickets[i], targetTickets);
            } 
            else {
                totalTime += Math.min(tickets[i], targetTickets - 1);
            }
        }
        
        return totalTime;
    }
}