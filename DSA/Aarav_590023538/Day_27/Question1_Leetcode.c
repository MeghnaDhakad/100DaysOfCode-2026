#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be modified in-place.
 * Return the new length of the compressed array.
 */
int compress(char* chars, int charsSize) {
    // Pointer to write compressed characters
    int write = 0;
    // Pointer to read the original array
    int read = 0;

    while (read < charsSize) {
        // Current character
        char current = chars[read];
        int count = 0;

        // Count consecutive occurrences of the current character
        while (read < charsSize && chars[read] == current) {
            read++;
            count++;
        }

        // Write the character
        chars[write++] = current;

        // If frequency is greater than 1, write its digits
        if (count > 1) {
            // Store count digits in reverse order
            char temp[10];
            int index = 0;
            while (count > 0) {
                temp[index++] = (count % 10) + '0';
                count /= 10;
            }
            // Write digits in correct order
            for (int i = index - 1; i >= 0; i--) {
                chars[write++] = temp[i];
            }
        }
    }

    // Return the length of the compressed array
    return write;
}

int main() {
    printf("Execution completed successfully.\n");
    return 0;
}
