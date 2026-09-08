#include <stdio.h>
#include <stdlib.h>

python
import heapq

def lastStoneStanding(rocks):
    heap = [-r for r in rocks]   # negate to turn min-heap into max-heap
    heapq.heapify(heap)

    while len(heap) > 1:
        y = -heapq.heappop(heap)  # heaviest
        x = -heapq.heappop(heap)  # second heaviest
        if y != x:
            heapq.heappush(heap, -(y - x))

    return -heap[0] if heap else 0


# Test cases
print(lastStoneStanding([2, 7, 4, 1, 8, 1]))  # 1
print(lastStoneStanding([10, 4, 2, 10]))       # 2
print(lastStoneStanding([1, 1]))               # 0

int main() {
    printf("Execution completed successfully.\n");
    return 0;
}
