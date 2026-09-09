class Solution {
    public int longestPalindrome(String s) {
        int[] hash = new int[128];

        for (char ch : s.toCharArray()) {
            hash[ch]++;
        }

        int length = 0;
        boolean hasOdd = false;

        for (int freq : hash) {
            length += (freq / 2) * 2;

            if (freq % 2 == 1) {
                hasOdd = true;
            }
        }

        if (hasOdd) {
            length++;
        }

        return length;
    }
}