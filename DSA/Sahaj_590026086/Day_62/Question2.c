#include <stdio.h>
#include <stdlib.h>

int rob(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    if (numsSize == 1) return nums[0];
    int prev2 = 0, prev1 = 0;
    for (int i = 0; i < numsSize; i++) {
        int curr = (prev2 + nums[i] > prev1) ? prev2 + nums[i] : prev1;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int main() {
    int h[] = {2, 7, 9, 3, 1};
    printf("%d\n", rob(h, 5));
    return 0;
}
