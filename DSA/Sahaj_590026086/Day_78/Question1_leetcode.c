#include <stdio.h>
#include <stdlib.h>

int singleNumber(int* nums, int numsSize) {
    int res = 0;
    for (int i = 0; i < numsSize; i++) res ^= nums[i];
    return res;
}

int main() {
    int nums[] = {4, 1, 2, 1, 2};
    printf("%d\n", singleNumber(nums, 5));
    return 0;
}
