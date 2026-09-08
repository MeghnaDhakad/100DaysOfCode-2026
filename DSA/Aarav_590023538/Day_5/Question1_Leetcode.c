#include <stdio.h>
#include <stdlib.h>

bool canJump(int* nums, int numsSize) {
    // Stores the farthest index we can reach
    int maxReach = 0;

    // Traverse the array
    for (int i = 0; i < numsSize; i++) {

        // If current index is not reachable
        if (i > maxReach) {
            return false;
        }

        // Update the farthest reachable index
        if (i + nums[i] > maxReach) {
            maxReach = i + nums[i];
        }

        // If we can reach the last index
        if (maxReach >= numsSize - 1) {
            return true;
        }
    }

    // Successfully traversed the array
    return true;
}

int main() {
    printf("Execution completed successfully.\n");
    return 0;
}
