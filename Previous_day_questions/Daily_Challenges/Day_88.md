<h2 align="center">Week 13 Day 88 (10/09/2026)</h2>

## 1. Array Partition (LeetCode #561)

A problem that teaches greedy algorithms for maximizing the sum of minimum elements by pairing numbers efficiently.

You are given an integer array `nums` containing `2n` integers. You need to group these integers into `n` pairs `(a1, b1), (a2, b2), ..., (an, bn)` such that the sum of `min(ai, bi)` for all pairs is maximized.

This problem helps build concepts like:
- Greedy algorithms
- Sorting
- Pairing strategy
- Optimization

which are important for solving arrangement and optimization problems efficiently.

**Your task:** Return the maximum possible sum of the minimum element from each pair.

### Input
An integer array:
- `nums`, containing `2n` integers.

**Constraints:**
- `1 <= n <= 10^4`
- `nums.length == 2 * n`
- `-10^4 <= nums[i] <= 10^4`

### Output
Return the maximum possible sum of the minimum element from each pair.

### Examples

**Input:**
```text
nums = [1, 4, 3, 2]
```

**Output:**
```text
4
```

---

**Input:**
```text
nums = [6, 2, 6, 5, 1, 2]
```

**Output:**
```text
9
```

---

## 2. Job Sequencing with Deadlines

A problem that teaches greedy algorithms for scheduling jobs to maximize the total profit.

You are given a set of jobs, where each job has a deadline and a profit. Each job takes exactly one unit of time to complete and can only be completed before or on its deadline.

The goal is to schedule the jobs in such a way that the total profit is maximized.

This problem helps build concepts like:
- Greedy algorithms
- Sorting by profit
- Scheduling
- Optimization

which are important for solving scheduling and resource allocation problems efficiently.

**Your task:** Determine the maximum total profit that can be obtained by scheduling the jobs optimally.

### Input
An integer `n` representing the number of jobs, followed by two arrays `deadline[]` and `profit[]`, where `deadline[i]` and `profit[i]` represent the deadline and profit of the `i`-th job.

**Constraints:**
- `1 <= n <= 10^5`
- `1 <= deadline[i] <= 10^5`
- `1 <= profit[i] <= 10^9`

### Output
Return the maximum total profit that can be obtained by scheduling the jobs before their respective deadlines.

### Examples

**Input:**
```text
n = 4
deadline = [4, 1, 1, 1]
profit = [20, 10, 40, 30]
```

**Output:**
```text
60
```

---
