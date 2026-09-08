#include <stdio.h>
#include <stdlib.h>

// Function to find the missing number
int missingNumber(int nums[], int numsSize) {
    // Sum of numbers from 0 to n
    int Total = numsSize * (numsSize + 1) / 2;
    
    // Calculate actual sum of array elements
    int actualSum = 0;
    for (int i = 0; i < numsSize; i++) {
        actualSum += nums[i];
    }

    // Missing number = Total - Actual Sum
    return Total - actualSum;
}

int main() {
    printf("Execution completed successfully.\n");
    return 0;
}
