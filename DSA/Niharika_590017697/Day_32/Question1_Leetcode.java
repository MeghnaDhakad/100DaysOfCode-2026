class Solution {
    public int minLength(String s) {
        StringBuilder stack = new StringBuilder();
        for (char ch : s.toCharArray()) 
        {
            if (stack.length() > 0) 
            {
                char top = stack.charAt(stack.length() - 1);
                if ((top == 'A' && ch == 'B') || (top == 'C' && ch == 'D')) 
                {
                    stack.deleteCharAt(stack.length() - 1);
                    continue;
                }
            }
            stack.append(ch);
        }

        return stack.length();
    }
}
