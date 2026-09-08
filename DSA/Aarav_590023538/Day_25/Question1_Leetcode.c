#include <stdlib.h>

// Comparator function for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int triangleNumber(int* nums, int numsSize) {
    // A triangle requires at least 3 sides
    if (numsSize < 3)
        return 0;

    // Sort the array in ascending order
    qsort(nums, numsSize, sizeof(int), compare);

    int count = 0;

    // Fix the largest side of the triangle
    for (int k = numsSize - 1; k >= 2; k--) {
        int left = 0;
        int right = k - 1;

        // Use two pointers to find valid pairs
        while (left < right) {
            // If the two smaller sides form a valid triangle
            if (nums[left] + nums[right] > nums[k]) {
                // Every element between left and right
                // will also satisfy the condition
                count += (right - left);
                // Try the next smaller value
                right--;
            }
            else {
                // Increase the smaller side
                left++;
            }
        }
    }

    return count;
}

int main() {
    printf("Execution completed successfully.\n");
    return 0;
}
