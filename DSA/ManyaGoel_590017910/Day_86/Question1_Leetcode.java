public class Question1_Leetcode {
    public int longestPalindrome(String s) {
        boolean[] seen = new boolean[128];
        int ans = 0;
        for (char c : s.toCharArray()) {
            if (seen[c]) {
                ans += 2;
                seen[c] = false;
            } else {
                seen[c] = true;
            }
        }
        return ans < s.length() ? ans + 1 : ans;
    }
}