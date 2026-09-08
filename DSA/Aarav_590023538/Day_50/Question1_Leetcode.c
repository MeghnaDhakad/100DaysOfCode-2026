#include <stdio.h>
#include <stdlib.h>

python
import heapq

def finalArray(nums, k, multiplier):
    heap = [(v, i) for i, v in enumerate(nums)]
    heapq.heapify(heap)

    for _ in range(k):
        v, i = heapq.heappop(heap)
        nums[i] = v * multiplier
        heapq.heappush(heap, (nums[i], i))

    return nums


# Test cases
print(finalArray([2, 1, 3, 5, 6], 5, 2))  # [8, 4, 6, 5, 6]
print(finalArray([1, 2], 3, 4))           # [16, 8]

int main() {
    printf("Execution completed successfully.\n");
    return 0;
}
