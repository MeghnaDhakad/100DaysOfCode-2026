#include <stdio.h>
#include <stdlib.h>

python
def merge(nums1, m, nums2, n):
    # Start filling from the back of nums1
    i = m - 1         # last valid element in nums1
    j = n - 1          # last element in nums2
    k = m + n - 1      # last position in nums1

    while j >= 0:
        if i >= 0 and nums1[i] > nums2[j]:
            nums1[k] = nums1[i]
            i -= 1
        else:
            nums1[k] = nums2[j]
            j -= 1
        k -= 1

    return nums1


# Test cases
print(merge([1,2,3,0,0,0], 3, [2,5,6], 3))  # [1,2,2,3,5,6]
print(merge([1], 1, [], 0))                  # [1]
print(merge([0], 0, [1], 1))                 # [1]

int main() {
    printf("Execution completed successfully.\n");
    return 0;
}
