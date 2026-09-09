int longestPalindrome(char* s) {
    int freq[256] = {0};
    int length = 0;
    int hasOdd = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        freq[(unsigned char)s[i]]++;
    }
    for (int i = 0; i < 256; i++) {
        if (freq[i] % 2 == 0) {
            length += freq[i];
        } else {
            length += freq[i] - 1;
            hasOdd = 1;
        }
    }
    if (hasOdd) {
        length++;
    }
    return length;
}