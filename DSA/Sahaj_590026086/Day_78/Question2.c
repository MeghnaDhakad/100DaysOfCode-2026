#include <stdio.h>
#include <stdlib.h>

int maxXorPair(int* nums, int numsSize) {
    int maxVal = 0;
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            int val = nums[i] ^ nums[j];
            if (val > maxVal) maxVal = val;
        }
    }
    return maxVal;
}

int main() {
    int nums[] = {3, 10, 5, 25, 2, 8};
    printf("%d\n", maxXorPair(nums, 6));
    return 0;
}
