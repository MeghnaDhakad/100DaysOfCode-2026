int longestPalindrome(char* s) {
    int freq[128] = {0};
    int length = 0;
    int hasOdd = 0;

    // Count frequency of each character
    for (int i = 0; s[i] != '\0'; i++) {
        freq[(unsigned char)s[i]]++;
    }

    // Calculate palindrome length
    for (int i = 0; i < 128; i++) {
        length += (freq[i] / 2) * 2;

        if (freq[i] % 2 == 1) {
            hasOdd = 1;
        }
    }

    // One odd-frequency character can be placed in the center
    if (hasOdd) {
        length++;
    }

    return length;
}
