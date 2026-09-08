#include <stdio.h>
#include <stdbool.h>

// Function to check if a pair with the target sum exists
bool hasPairWithTarget(int arr[], int size, int target) {
    // Initialize two pointers
    int left = 0;
    int right = size - 1;

    // Continue until the pointers meet
    while (left < right) {
        int sum = arr[left] + arr[right];

        // Pair found
        if (sum == target) {
            return true;
        }
        // If sum is smaller, move the left pointer forward
        if (sum < target) {
            left++;
        }
        // If sum is larger, move the right pointer backward
        else {
            right--;
        }
    }

    // No valid pair found
    return false;
}

int main() {
    int size, target;

    // Input the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    // Input the sorted array elements
    printf("Enter the sorted array elements: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Input the target value
    printf("Enter the target sum: ");
    scanf("%d", &target);

    // Check if a valid pair exists
    if (hasPairWithTarget(arr, size, target))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
