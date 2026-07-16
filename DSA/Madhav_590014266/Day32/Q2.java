class Solution {
    public Stack<Integer> copyStack(Stack<Integer> st) {
        Stack<Integer> temp = new Stack<>();
        Stack<Integer> copy = new Stack<>();

        while (!st.isEmpty()) {
            temp.push(st.pop());
        }

        while (!temp.isEmpty()) {
            int val = temp.pop();
            st.push(val);
            copy.push(val);
        }

        return copy;
    }
}