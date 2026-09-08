#include <stdio.h>
#include <stdlib.h>

int canPartition(int* nums, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) sum += nums[i];
    return sum % 2 == 0;
}

int main() {
    int nums[] = {1, 5, 11, 5};
    printf("%s\n", canPartition(nums, 4) ? "true" : "false");
    return 0;
}
