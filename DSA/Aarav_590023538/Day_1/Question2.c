#include <stdio.h>

int main() {
    // Variable to store the size of the array
    int n;

    // Take the size of the array as input
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Declare the array
    int arr[n];

    // Variable to store the sum of elements
    int sum=0;

    // Take array elements as input from the user
    printf("Enter %d elements:\n", n);
    for (int i=0;i<n;i++) {
        scanf("%d", &arr[i]);
    }

    // Traverse the array and calculate the sum
    for (int i=0;i<n;i++) {
        sum=sum+arr[i];
    }

    // Display the result
    printf("Sum of array elements is %d\n",sum);
    return 0;
}
