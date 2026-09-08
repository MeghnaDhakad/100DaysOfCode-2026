#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Comparator function used by qsort() to sort the array
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Function to check whether a valid triplet exists
bool checkTriplet(int arr[], int n) {
    // Sort the array in ascending order
    qsort(arr, n, sizeof(int), compare);

    // Consider each element as the largest element of the triplet
    for (int i = n - 1; i >= 2; i--) {
        int left = 0;
        int right = i - 1;

        // Use two pointers to find two numbers whose sum equals arr[i]
        while (left < right) {
            int sum = arr[left] + arr[right];

            // Triplet found
            if (sum == arr[i]) {
                return true;
            }
            // Increase the sum by moving the left pointer
            else if (sum < arr[i]) {
                left++;
            }
            // Decrease the sum by moving the right pointer
            else {
                right--;
            }
        }
    }

    // No valid triplet exists
    return false;
}

int main() {
    int n;

    // Input the size of the array
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Input array elements
    printf("Enter the array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Check and display the result
    if (checkTriplet(arr, n))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
