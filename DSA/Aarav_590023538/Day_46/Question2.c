#include <stdio.h>
#include <stdlib.h>

python
def max_prefix_diff_score(nums):
    n = len(nums)
    if n <= 1:
        return 0

    lo = hi = nums[0]
    for x in nums[1:]:
        if x < lo: lo = x
        if x > hi: hi = x

    return (n - 1) * (hi - lo)

int main() {
    printf("Execution completed successfully.\n");
    return 0;
}
