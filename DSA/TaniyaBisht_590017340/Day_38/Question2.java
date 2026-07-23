
import java.util.*;
class CT{
    public static void main(String[] args){
        int n = 4;
        Queue<Integer> q = new LinkedList<>();
        for(int i = 1; i <= n; i++) {
            q.add(i);
        }
        int[] deck = new int[n];
        for(int card = 1; card <= n; card++){
            int pos = q.remove();
            deck[pos - 1] = card;
            if(!q.isEmpty()){
                q.add(q.remove());
            }
        }
        System.out.println(Arrays.toString(deck));
    }
}