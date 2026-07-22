import java.util.Scanner;

import java.util.ArrayDeque;
import java.util.Deque;



public class Question2 {
    public static void main(String[]args){
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter number of cards:");
        int n=sc.nextInt();
      
        Deque<Integer> q=new ArrayDeque<>();
        for(int i=n;i>=1;i--){
            if(q.isEmpty()){
                q.addFirst(q.removeLast());

            }
            
             q.addFirst(i);
        
            
        }
        while(!q.isEmpty()){
            System.out.println(q.removeFirst()+" ");

        }
        
sc.close();
    }
    
}
