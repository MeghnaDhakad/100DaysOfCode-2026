<h2 align="center">Week 6 Day 4 (23/07/2026)</h2>

## 1. Time Needed to Buy Tickets (LeetCode #2073)
A problem that teaches simulation and array-processing techniques by finding how long a specific person takes to finish buying tickets while queuing in a circular fashion. There are n people in a line queuing to buy tickets, where the 0th person is at the front of the line and the (n - 1)th person is at the back of the line. You are given a 0-indexed integer array tickets of length n where the number of tickets that the ith person would like to buy is tickets[i]. Each person takes exactly 1 second to buy a ticket. A person can only buy 1 ticket at a time and has to go back to the end of the line (which happens instantaneously) in order to buy more tickets. If a person does not have any tickets left to buy, the person will leave the line.

This problem is commonly asked in interviews and helps build concepts like:
- Simulation
- Array traversal
- Queue behavior

which are important for solving time/order-based simulation problems efficiently.

**Your task:** Return the time taken for the person initially at position k (0-indexed) to finish buying tickets.

### Input
An integer array `tickets` and an integer `k`, as described above.

**Constraints:**
- `n == tickets.length`
- `1 <= n <= 100`
- `1 <= tickets[i] <= 100`
- `0 <= k < n`

### Output
Return the time taken for the person initially at position k to finish buying tickets.

### Examples

**Input:**
```
tickets = [2,3,2], k = 2
```
**Output:**
```
6
```

---

**Input:**
```
tickets = [5,1,1,1], k = 0
```
**Output:**
```
8
```

---

## 2. Minimum Conference Rooms Required
A scheduling problem that requires finding the minimum number of rooms needed to host all meetings. A company has several meetings scheduled throughout the day. Each meeting is represented by a start time and an end time. Two meetings cannot be held in the same conference room if their time intervals overlap. However, once a meeting ends, that room becomes available and can be used for another meeting.

This problem is commonly asked in interviews and helps build concepts like:
- Interval scheduling
- Sorting
- Heap / greedy techniques

which are important for solving resource-allocation and scheduling problems efficiently.

**Your task:** Given a list of meeting intervals, find the minimum number of conference rooms required.

### Input
A list of meeting intervals, as described above.

**Constraints:**
- `1 <= intervals.length <= 100000`
- `0 <= start_i < end_i <= 1000000`

### Output
Return the minimum number of conference rooms required.

### Examples

**Input:**
```
intervals = [[0, 30], [5, 10], [15, 20]]
```
**Output:**
```
2
```

---

**Input:**
```
intervals = [[7, 10], [2, 4]]
```
**Output:**
```
1
```

---

**Input:**
```
intervals = [[1, 5], [2, 6], [4, 8], [9, 10]]
```
**Output:**
```
3
```

---
