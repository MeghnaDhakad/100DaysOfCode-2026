#include <stdio.h>
#include <stdlib.h>

// Sort the array containing only 0s, 1s, and 2s
void sortColors(int* nums, int numsSize) {
    // Initialize three pointers
    int low = 0;
    int mid = 0;
    int high = numsSize - 1;

    // Traverse the array
    while (mid <= high) {
        // If current element is 0, move it to the beginning
        if (nums[mid] == 0) {
            int temp = nums[low];
            nums[low] = nums[mid];
            nums[mid] = temp;
            low++;
            mid++;
        }
        // If current element is 1, it is already in the correct position
        else if (nums[mid] == 1) {
            mid++;
        }
        // If current element is 2, move it to the end
        else {
            int temp = nums[mid];
            nums[mid] = nums[high];
            nums[high] = temp;
            high--;
        }
    }
}

int main() {
    printf("Execution completed successfully.\n");
    return 0;
}
