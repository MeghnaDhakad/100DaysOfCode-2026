#include <stdio.h>
#include <stdlib.h>

void moveZeroes(int* nums, int numsSize)
{
    int j = 0; // Position to place the next non-zero element
    // Traverse the array
    for (int i = 0; i < numsSize; i++)
    {
        // If the current element is non-zero
        if (nums[i] != 0)
        {
            // Swap the current element with the element at index j
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            // Move j to the next position
            j++;
        }
    }
}

int main() {
    printf("Execution completed successfully.\n");
    return 0;
}
