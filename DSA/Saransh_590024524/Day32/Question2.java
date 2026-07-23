package DSA.Saransh_590024524.Day32;

import java.util.Stack;

class Solution {

    public Stack<Integer> copyStack(Stack<Integer> st) {

        Stack<Integer> temp = new Stack<>();
        Stack<Integer> copy = new Stack<>();
        while (!st.isEmpty()) {
            int value = st.pop();
            temp.push(value);
        }
        while (!temp.isEmpty()) {
            int value = temp.pop();

            st.push(value);
            copy.push(value);
        }
        return copy;
    }
}
