class Solution {
    public int longestPalindrome(String s) {
        int[] freq = new int[128];

        // Count frequency of each character
        for (char ch : s.toCharArray()) {
            freq[ch]++;
        }

        int length = 0;
        boolean hasOdd = false;

        for (int count : freq) {
            // Take the largest even part
            length += (count / 2) * 2;

            // One odd-frequency character can be placed in the center
            if (count % 2 == 1) {
                hasOdd = true;
            }
        }

        if (hasOdd) {
            length++;
        }

        return length;
    }
}
