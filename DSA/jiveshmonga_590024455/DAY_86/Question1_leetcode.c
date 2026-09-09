int longestPalindrome(char* s) {
    int freq[128] = {0};
    int length = 0;
    int odd = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        freq[(int)s[i]]++;
    }

    for (int i = 0; i < 128; i++) {
        length += (freq[i] / 2) * 2;

        if (freq[i] % 2 == 1)
            odd = 1;
    }

    if (odd)
        length++;

    return length;
}