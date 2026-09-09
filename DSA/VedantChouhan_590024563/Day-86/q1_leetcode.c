#include <stdio.h>

int longestPalindrome(char s[]) {
    int freq[52] = {0};

    // Count frequency of each character
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] >= 'a' && s[i] <= 'z')
            freq[s[i] - 'a']++;
        else
            freq[s[i] - 'A' + 26]++;
    }

    int length = 0;
    int hasOdd = 0;

    // Use pairs of characters
    for (int i = 0; i < 52; i++) {
        length += (freq[i] / 2) * 2;

        if (freq[i] % 2 == 1)
            hasOdd = 1;
    }

    // One odd-frequency character can be placed in the middle
    if (hasOdd)
        length++;

    return length;
}

int main() {
    char s[2001];

    printf("Enter a string: ");
    scanf("%2000s", s);

    printf("Longest palindrome length: %d\n", longestPalindrome(s));

    return 0;
}