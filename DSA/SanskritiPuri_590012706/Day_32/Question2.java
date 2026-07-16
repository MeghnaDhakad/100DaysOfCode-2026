import java.util.Stack;

public class Solution {

    public static Stack<Integer> copyStack(Stack<Integer> st) {
        Stack<Integer> copy = new Stack<>();
        copyHelper(st, copy);
        return copy;
    }

    private static void copyHelper(Stack<Integer> st, Stack<Integer> copy) {
        if (st.isEmpty()) {
            return;
        }

        int top = st.pop();
        copyHelper(st, copy);

        st.push(top);
        copy.push(top);
    }
}
