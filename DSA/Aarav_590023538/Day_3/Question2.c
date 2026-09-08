#include <stdio.h>

// Function to count the occurrences of the target element
int countOccurrences(int arr[], int n, int target)
{
    int count = 0;
    // Traverse the entire array
    for (int i = 0; i < n; i++)
    {
        // If the current element matches the target,
        // increase the count
        if (arr[i] == target)
        {
            count++;
        }
    }
    // Return the total count
    return count;
}

int main()
{
    int n, target;
    // Read the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    // Read the array elements
    printf("Enter %d sorted elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    // Read the target element
    printf("Enter the target element: ");
    scanf("%d", &target);
    // Call the function to count occurrences
    int result = countOccurrences(arr, n, target);
    // Display the result
    printf("Number of occurrences of %d = %d\n", target, result);
    return 0;
}
