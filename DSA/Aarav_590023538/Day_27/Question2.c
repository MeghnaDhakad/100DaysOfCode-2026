#include <stdio.h>

// Function to count subarrays whose maximum element
// is less than or equal to the given limit
int countSubarrays(int arr[], int n, int limit) {
    int count = 0;
    int length = 0;

    for (int i = 0; i < n; i++) {
        // If the current element is within the limit,
        // increase the current valid segment length
        if (arr[i] <= limit) {
            length++;
        } else {
            // Otherwise, start a new segment
            length = 0;
        }
        // Add the number of valid subarrays
        // ending at the current index
        count += length;
    }

    return count;
}

int main() {
    int n;

    // Input the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    // Input array elements
    printf("Enter the array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int left, right;

    // Input the range
    printf("Enter left and right: ");
    scanf("%d %d", &left, &right);

    // Count subarrays with maximum <= right
    int rightCount = countSubarrays(arr, n, right);
    // Count subarrays with maximum < left
    int leftCount = countSubarrays(arr, n, left - 1);

    // Required answer
    int result = rightCount - leftCount;
    printf("Number of valid subarrays = %d\n", result);

    return 0;
}
