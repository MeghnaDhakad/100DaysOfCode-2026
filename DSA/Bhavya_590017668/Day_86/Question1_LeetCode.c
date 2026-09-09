int longestPalindrome(char* s) {
    int freq[128] = {0};
    int length = 0;
    
    for (int i = 0; s[i] != '\0'; i++)
        freq[(unsigned char)s[i]]++;
    
    for (int i = 0; i < 128; i++)
        length += (freq[i] / 2) * 2;
    
    if (length < (int)strlen(s))
        length++;
    
    return length;
}