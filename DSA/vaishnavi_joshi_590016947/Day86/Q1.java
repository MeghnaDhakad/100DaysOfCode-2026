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

            // Check if an odd character exists
            if (count % 2 == 1) {
                hasOdd = true;
            }
        }

        // One odd character can be placed in the center
        if (hasOdd) {
            length++;
        }

        return length;
    }
}