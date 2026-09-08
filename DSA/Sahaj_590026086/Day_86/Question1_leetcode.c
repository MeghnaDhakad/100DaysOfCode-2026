#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int longestPalindrome(char* s) {
    int freq[128] = {0};
    int len = strlen(s);
    for (int i = 0; i < len; i++) freq[(unsigned char)s[i]]++;
    int result = 0;
    bool hasOdd = false;
    for (int i = 0; i < 128; i++) {
        result += (freq[i] / 2) * 2;
        if (freq[i] % 2 != 0) hasOdd = true;
    }
    if (hasOdd) result++;
    return result;
}

int main() {
    char s[] = "abccccdd";
    printf("%d\n", longestPalindrome(s));
    return 0;
}
