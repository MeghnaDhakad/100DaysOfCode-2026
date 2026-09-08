#include <stdio.h>
#include <stdlib.h>

python
def intersection(nums1, nums2):
    return list(set(nums1) & set(nums2))

int main() {
    printf("Execution completed successfully.\n");
    return 0;
}
