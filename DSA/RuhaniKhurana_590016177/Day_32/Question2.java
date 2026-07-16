import java.util.*;

public class Question2 {
    public static void main(String[] args) {

        Stack<Integer> rt = new Stack<>();
        rt.push(1);
        rt.push(2);
        rt.push(3);
        rt.push(4);

        Stack<Integer> temp = new Stack<>();
        Stack<Integer> copy = new Stack<>();

        while (!rt.isEmpty()) {
            temp.push(rt.pop());
        }
        while (!temp.isEmpty()) {
            int x = temp.pop();
            rt.push(x);
            copy.push(x);
        }

        System.out.println(copy);
    }
}