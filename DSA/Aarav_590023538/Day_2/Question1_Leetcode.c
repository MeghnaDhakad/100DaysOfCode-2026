#include <stdio.h>
#include <stdlib.h>

// Function to remove all occurrences of val from the array in-place
int removeElement(int* nums, int numsSize, int val) {
    // Index to track position of next valid element
    int k = 0;

    // Traverse the array
    for (int i = 0; i < numsSize; i++) {
        // If current element is not val, keep it
        if (nums[i] != val) {
            nums[k] = nums[i];
            k++;
        }
    }

    // Return count of remaining elements
    return k;
}

int main() {
    printf("Execution completed successfully.\n");
    return 0;
}
