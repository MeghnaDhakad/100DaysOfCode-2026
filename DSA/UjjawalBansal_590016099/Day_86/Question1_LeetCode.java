public class Question1_LeetCode {
    public int longestPalindrome(String s) {
        int[] chars = new int[128]; 
        for (char c : s.toCharArray()) {
            chars[c]++;
        }
        int ans = 0;
        boolean hasOdd = false;
        
        for (int count : chars) {
            ans += (count / 2) * 2;

            if (count % 2 != 0) {
                hasOdd = true;
            }
        }
        if (hasOdd) {
            ans++;
        }
        return ans;
    }
}
