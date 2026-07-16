class Solution {
    public int minLength(String s) {
        StringBuilder stack = new StringBuilder();

        for (char ch : s.toCharArray()) {
            stack.append(ch);

            int n = stack.length();
            if (n >= 2) {
                char secondLast = stack.charAt(n - 2);
                char last = stack.charAt(n - 1);

                if ((secondLast == 'A' && last == 'B') ||
                    (secondLast == 'C' && last == 'D')) {
                    stack.delete(n - 2, n);
                }
            }
        }

        return stack.length();
        
    }
}
