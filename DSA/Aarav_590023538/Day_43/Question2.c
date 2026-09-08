#include <stdio.h>
#include <stdlib.h>

python
def maxSumPairMin(nums):
    nums.sort()
    return sum(nums[0::2])  # sum every element at even index (0, 2, 4, ...)


# Test cases
print(maxSumPairMin([1, 4, 3, 2]))       # 4
print(maxSumPairMin([6, 2, 6, 5, 1, 2])) # 9
print(maxSumPairMin([1, 2, 3, 4]))       # 4

int main() {
    printf("Execution completed successfully.\n");
    return 0;
}
