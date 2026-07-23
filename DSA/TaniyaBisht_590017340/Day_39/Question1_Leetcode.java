
class Solution {
    public int timeRequiredToBuy(int[] tickets, int k) {
         Queue<Integer> qu = new LinkedList<>();
         for(int i=0; i<tickets.length; i++){
            qu.add(i);
         }
         int sec = 0;
         while(!qu.isEmpty()){
            sec++;
            int per = qu.poll();
            if(tickets[per] >= 1){
                tickets[per]--;
            }
            if(per==k && tickets[per] == 0){
                break;
            }
            if(per!=k && tickets[per] == 0){
                continue;
            }
            qu.add(per);
         }
         return sec;
    }
}