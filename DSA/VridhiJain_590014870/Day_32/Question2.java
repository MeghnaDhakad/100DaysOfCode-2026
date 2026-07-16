import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Stack<Integer> st = new Stack<>();
        Stack<Integer> temp = new Stack<>();
        Stack<Integer> copy = new Stack<>();
        for (int i = 0; i < n; i++) {
            st.push(sc.nextInt());
        }
        while (!st.isEmpty()) {
            temp.push(st.pop());
        }
        while (!temp.isEmpty()) {
            int x = temp.pop();
            st.push(x);
            copy.push(x);
        }
        System.out.println(copy);
    }
}