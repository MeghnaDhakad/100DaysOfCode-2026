#include <stdio.h>
#include <stdlib.h>

// Function to find the maximum money that can be robbed
// from a linear range of houses
int solve(int* arr, int left, int right) {
    int first = 0, second = 0;

    // Traverse the given range of houses
    for (int i = left; i <= right; i++) {

        // Choose the maximum of:
        // 1. Rob current house (second + arr[i])
        // 2. Skip current house (first)
        int ans = (second + arr[i] > first) ? second + arr[i] : first;

        // Update previous values
        second = first;
        first = ans;
    }

    return first;
}

int rob(int* nums, int numsSize) {

    // If there is only one house
    if (numsSize == 1)
        return nums[0];

    // Case 1: Exclude the last house
    int case1 = solve(nums, 0, numsSize - 2);

    // Case 2: Exclude the first house
    int case2 = solve(nums, 1, numsSize - 1);

    // Return the maximum amount from both cases
    return (case1 > case2) ? case1 : case2;
}

int main() {
    printf("Execution completed successfully.\n");
    return 0;
}
