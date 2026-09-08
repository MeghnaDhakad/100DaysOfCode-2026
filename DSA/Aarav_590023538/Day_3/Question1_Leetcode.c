#include <stdio.h>
#include <stdlib.h>

// Function to add one to the number represented by the array
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    // Traverse the array from the last digit
    for (int i = digitsSize - 1; i >= 0; i--) {
        // If current digit is less than 9, increment and return
        if (digits[i] < 9) {
            digits[i]++;
            *returnSize = digitsSize;
            return digits;
        }
        // Otherwise set digit to 0 and carry over to the next digit
        digits[i] = 0;
    }

    // If all digits were 9, allocate a new array with an extra leading digit
    int* result = (int*)malloc((digitsSize + 1) * sizeof(int));
    result[0] = 1;
    for (int i = 0; i < digitsSize; i++) {
        result[i + 1] = 0;
    }

    *returnSize = digitsSize + 1;
    return result;
}

int main() {
    printf("Execution completed successfully.\n");
    return 0;
}
