package Day_39;
import java.util.*;
class Solution {
    public int timeRequiredToBuy(int[] tickets, int k) {
        Queue<Integer> queue = new ArrayDeque<>();
        int time=0;
        for(int i=0; i < tickets.length; i++){
            queue.offer(i);
        }
        while (!queue.isEmpty()){
            int person=queue.poll();
            tickets[person]--;
            time++;
            if(tickets[person] == 0 && person == k){
                return time;
        }
            if (tickets[person] > 0){
                queue.offer(person);
        }
        }
        return -1;
    }
}