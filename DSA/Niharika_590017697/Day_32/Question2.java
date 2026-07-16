import java.util.Scanner;
import java.util.Stack;

public class Question2 
{
    public static Stack<Integer> copyStack(Stack<Integer> st) 
    {
        Stack<Integer> temp = new Stack<>();
        Stack<Integer> copy = new Stack<>();

        while (!st.isEmpty()) 
        {
            temp.push(st.pop());
        }

        while (!temp.isEmpty()) 
        {
            int x = temp.pop();
            st.push(x);
            copy.push(x);
        }
        return copy;
    }

    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(); 
        Stack<Integer> st = new Stack<>();

        for (int i = 0; i < n; i++) 
        {
            st.push(sc.nextInt());
        }
        Stack<Integer> copiedStack = copyStack(st);
        System.out.println(copiedStack);

        sc.close();
    }
}
