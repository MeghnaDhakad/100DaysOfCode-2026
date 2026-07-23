import heapq
from typing import List

def min_meeting_rooms(intervals: List[List[int]]) -> int:
    """
    Returns the minimum number of conference rooms required
    so that no two overlapping meetings share a room.
    """
    if not intervals:
        return 0
    
    # Sort meetings by start time
    intervals.sort(key=lambda x: x[0])
    
    # Min-heap to track end times of meetings currently using a room
    heap = []
    
    for start, end in intervals:
        # If the earliest-ending meeting has already finished
        # by the time this one starts, that room is now free — reuse it.
        if heap and heap[0] <= start:
            heapq.heappop(heap)
        
        # Assign a room to this meeting (either reused or a new one)
        heapq.heappush(heap, end)
    
    # The heap size at the end = max rooms used simultaneously
    return len(heap)


# ---- Local testing block ----
if __name__ == "__main__":
    intervals = [[1, 5], [2, 6], [4, 8], [9, 10]]
    print(min_meeting_rooms(intervals))  # Output: 3