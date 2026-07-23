<h2 align="center">Week 6 Day 39 (23/07/2026)</h2>

## 1. Time Needed to Buy Tickets (LeetCode #2073)

### Solution

```python
# Simple simulation approach - O(n * max_tickets)
def time_required_to_buy(tickets, k):
    time = 0
    i = 0
    n = len(tickets)
    while tickets[k] > 0:
        if tickets[i] > 0:
            tickets[i] -= 1
            time += 1
        i = (i + 1) % n
    return time
```

Better O(n) approach — no simulation needed. For each person `i`:

* If `i <= k`: they buy up to `min(tickets[i], tickets[k])` tickets before person k finishes.
* If `i > k`: they only get a turn before k's last ticket if `tickets[i] < tickets[k]`, so they contribute `min(tickets[i], tickets[k] - 1)`.

```python
# Optimized O(n) approach
def time_required_to_buy(tickets, k):
    time = 0
    for i, t in enumerate(tickets):
        if i <= k:
            time += min(t, tickets[k])
        else:
            time += min(t, tickets[k] - 1)
    return time
```

Verified with samples:

* `tickets=[2,3,2], k=2` → `min(2,2) + min(3,2) + min(2,2) = 2+2+2 = 6` ✅
* `tickets=[5,1,1,1], k=0` → `min(5,5) + min(1,4) + min(1,4) + min(1,4) = 5+1+1+1 = 8` ✅

---

## 2. Minimum Conference Rooms Required

### Solution

Heap-based approach (O(n log n)) — track end times of rooms currently in use:

```python
import heapq

def min_meeting_rooms(intervals):
    if not intervals:
        return 0

    intervals.sort(key=lambda x: x[0])
    heap = []  # stores end times of ongoing meetings

    for start, end in intervals:
        if heap and heap[0] <= start:
            heapq.heapreplace(heap, end)  # reuse the room
        else:
            heapq.heappush(heap, end)     # need a new room

    return len(heap)
```

Alternative: two-pointer approach (also O(n log n), often preferred):

```python
def min_meeting_rooms(intervals):
    if not intervals:
        return 0

    starts = sorted(i[0] for i in intervals)
    ends = sorted(i[1] for i in intervals)

    rooms = 0
    max_rooms = 0
    s = e = 0
    n = len(intervals)

    while s < n:
        if starts[s] < ends[e]:
            rooms += 1
            s += 1
        else:
            rooms -= 1
            e += 1
        max_rooms = max(max_rooms, rooms)

    return max_rooms
```

Verified with samples:

* `[[0,30],[5,10],[15,20]]` → 2 ✅ (meeting [0,30] overlaps both others, but [5,10] and [15,20] don't overlap each other)
* `[[7,10],[2,4]]` → 1 ✅ (no overlap)
* `[[1,5],[2,6],[4,8],[9,10]]` → 3 ✅ (at time 4, meetings [1,5],[2,6],[4,8] are all active)

Both solutions handle the given constraints efficiently — Problem 1's O(n) version and Problem 2's O(n log n) version will comfortably handle the max input sizes (n=100 and n=100,000 respectively).
