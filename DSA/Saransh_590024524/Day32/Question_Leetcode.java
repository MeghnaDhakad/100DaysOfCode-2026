package DSA.Saransh_590024524.Day32;

import java.util.Stack;

    public class Question_Leetcode {
        public int minLength(String s) {
            Stack<Character> st = new Stack<>();

            for (char ch : s.toCharArray()) {
                if (!st.isEmpty() &&
                ((st.peek() == 'A' && ch == 'B') ||
                    (st.peek() == 'C' && ch == 'D'))) {
                    st.pop();
                } else {
                    st.push(ch);
                }
            }

            return st.size();
    }
}

