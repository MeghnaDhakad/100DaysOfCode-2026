#include <stdbool.h>
#include <string.h>

// Function to check if all characters occur the same number of times
bool areOccurrencesEqual(char* s) {
    // Frequency array for lowercase English letters
    int freq[26] = {0};
    int len = strlen(s);

    // Count occurrences of each character
    for (int i = 0; i < len; i++) {
        freq[s[i] - 'a']++;
    }

    // Find the frequency of the first character that appears
    int target = -1;
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            target = freq[i];
            break;
        }
    }

    // Compare every other character's frequency with target
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0 && freq[i] != target) {
            return false;
        }
    }

    return true;
}

int main() {
    printf("Execution completed successfully.\n");
    return 0;
}
