#include <stdio.h>
#include <stdlib.h>

int singleNumber(int* nums, int numsSize) {
    int ones = 0, twos = 0;
    for (int i = 0; i < numsSize; i++) {
        ones = (ones ^ nums[i]) & ~twos;
        twos = (twos ^ nums[i]) & ~ones;
    }
    return ones;
}

int main() {
    int nums[] = {2, 2, 3, 2};
    printf("%d\n", singleNumber(nums, 4));
    return 0;
}
