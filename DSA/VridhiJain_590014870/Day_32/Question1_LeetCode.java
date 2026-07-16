import java.util.*;
class Solution {
    public int minLength(String s) {
        Stack<Character> stack = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            if (!stack.isEmpty()) {
                char top = stack.peek();
                if ((top == 'A' && ch == 'B') ||
                    (top == 'C' && ch == 'D')) {
                    stack.pop();
                    continue;
                }
            }
            stack.push(ch);
        }
        return stack.size();
    }
}