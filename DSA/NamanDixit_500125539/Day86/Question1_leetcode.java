class Question1_leetcode {
    
    // Function to find the length of the longest palindrome
    static int longestPalindrome(String s) {

        // There are 128 ASCII characters
        // We use an array to store the count of each character
        int[] count = new int[128];

        // Count every character in the string
        for (int i = 0; i < s.length(); i++) {

            // Get the current character
            char ch = s.charAt(i);

            // Increase its count by 1
            count[ch]++;
        }

        // This stores the length of the palindrome
        int length = 0;

        // This tells us whether we have an odd-count
        // character that can be placed in the middle
        boolean hasOdd = false;

        // Check every character
        for (int i = 0; i < 128; i++) {

            // Take as many pairs as possible
            //
            // Example:
            // count = 5
            // 5 / 2 = 2 pairs
            // 2 pairs = 4 characters
            length = length + (count[i] / 2) * 2;

            // Check if the character occurs an odd number of times
            if (count[i] % 2 == 1) {

                // We have an extra character
                // that can potentially go in the middle
                hasOdd = true;
            }
        }

        // If we have at least one odd-count character,
        // we can put ONE of them in the middle
        if (hasOdd) {
            length++;
        }

        // Return the maximum palindrome length
        return length;
    }
}