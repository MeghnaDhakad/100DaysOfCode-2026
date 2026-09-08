#include <stdio.h>
#include <stdlib.h>

int lengthOfLastWord(char* s) {
    int i = 0;
    int length = 0;

    // Find the end of the string
    while (s[i] != '\0') {
        i++;
    }

    // Move backwards and skip trailing spaces
    i--;
    while (i >= 0 && s[i] == ' ') {
        i--;
    }

    // Count characters of the last word
    while (i >= 0 && s[i] != ' ') {
        length++;
        i--;
    }

    return length;
}

int main() {
    printf("Execution completed successfully.\n");
    return 0;
}
