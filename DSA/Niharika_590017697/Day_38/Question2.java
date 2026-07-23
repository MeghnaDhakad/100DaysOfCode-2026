import java.util.*;
public class Question2 
{
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Deque<Integer> deque = new ArrayDeque<>();

        for (int i = n; i >= 1; i--) 
        {
            if (!deque.isEmpty()) 
            {
                deque.addFirst(deque.removeLast());
            }
            deque.addFirst(i);
        }
        System.out.println(deque);
    }
}
