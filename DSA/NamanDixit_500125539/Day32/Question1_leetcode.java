
import java.util.Stack;

class Solution {

    public int minLength(String s) {

        // Create stack
        Stack<Character> stack = new Stack<>();

        // Traverse string
        for (int i = 0; i < s.length(); i++) {

            // Current character
            char ch = s.charAt(i);

            // Check for removable pair
            if (!stack.isEmpty()) {

                char top = stack.peek();

                if ((top == 'A' && ch == 'B') ||
                    (top == 'C' && ch == 'D')) {

                    // Remove the pair
                    stack.pop();
                    continue;
                }
            }

            // Push current character
            stack.push(ch);
        }

        // Remaining length
        return stack.size();
    }
}