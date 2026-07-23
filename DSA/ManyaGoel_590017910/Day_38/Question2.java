import java.util.*;
public class Question2 {
    public static int[] InitialDeck( int n){
        Deque <Integer> deck = new ArrayDeque<>();
        for(int i=n;i>=1;i--){
            if(!deck.isEmpty()){
                int last =  deck.removeLast();
                deck.addFirst(last);
            }
        
        deck.addFirst(i);
    }
    int[] result = new int[n];
    int index=0;
    while(!deck.isEmpty()){
        result[index++]= deck.removeFirst();
    }
    return result;
}
    public static void main(String[] args) {
        Scanner sc = new Scanner (System.in);
       
        System.out.print("Enter the number of cards: ");
        int n = sc.nextInt();

        int[] initialDeck = InitialDeck(n);
        System.out.println("Required initial arrangement: " + Arrays.toString(initialDeck));
        sc.close();
    }
}