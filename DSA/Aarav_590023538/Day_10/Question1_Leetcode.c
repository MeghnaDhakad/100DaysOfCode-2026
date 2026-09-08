#include <stdio.h>
#include <stdlib.h>

int strStr(char* haystack, char* needle) {
    // If needle is empty, return 0
    if (needle[0] == '\0')
        return 0;
    int i, j;
    // Check every possible starting position in haystack
    for (i = 0; haystack[i] != '\0'; i++) {
        j = 0;
        // Compare characters of needle with haystack
        while (needle[j] != '\0' &&
               haystack[i + j] != '\0' &&
               haystack[i + j] == needle[j]) {
            j++;
        }
        // If we reached the end of needle,
        // then the whole substring matched
        if (needle[j] == '\0')
            return i;
    }
    // Substring not found
    return -1;
}

int main() {
    printf("Execution completed successfully.\n");
    return 0;
}
