#include <stdbool.h>
#include <string.h>

bool isPalindrome(char *s) {
    char str[100000];
    int k = 0;

    // Copy only letters and digits
    for (int i = 0; s[i] != '\0'; i++) {
        // Convert uppercase to lowercase
        if (s[i] >= 'A' && s[i] <= 'Z') {
            str[k++] = s[i] + 32;
        }
        // Store lowercase letters
        else if (s[i] >= 'a' && s[i] <= 'z') {
            str[k++] = s[i];
        }
        // Store digits
        else if (s[i] >= '0' && s[i] <= '9') {
            str[k++] = s[i];
        }
    }

    // Check palindrome
    int left = 0;
    int right = k - 1;
    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main() {
    printf("Execution completed successfully.\n");
    return 0;
}
