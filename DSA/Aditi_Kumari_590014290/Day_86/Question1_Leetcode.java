package DSA.Aditi_Kumari_590014290.Day_86;

class Solution {
    public int longestPalindrome(String s) {
        int[] freq = new int[128];
        for (char c : s.toCharArray()) {
            freq[c]++;
        }
        int length = 0;
        boolean odd = false;
        for (int count : freq) {
            length += (count / 2) * 2;

            if (count % 2 == 1) {
                odd = true;
            }
        }
        if (odd) {
            length++;
        }
        return length;
    }
}