<h2 align="center">Week 13 Day 85 (07/09/2026)</h2>

## 1. Assign Cookies (LeetCode #455)

A problem that teaches greedy algorithms for maximizing the number of children that can be satisfied by assigning cookies efficiently.

You are given two integer arrays `g` and `s`, where `g[i]` represents the minimum cookie size required to satisfy the `i`-th child and `s[j]` represents the size of the `j`-th cookie. Each child can receive at most one cookie.

If `s[j] >= g[i]`, the cookie can be assigned to the child and the child becomes content.

This problem helps build concepts like:
- Greedy algorithms
- Sorting
- Two-pointer technique
- Optimal assignment

which are important for solving allocation and optimization problems efficiently.

**Your task:** Return the maximum number of children who can be made content.

### Input
Two integer arrays:
- `g`, where `g[i]` represents the greed factor of each child.
- `s`, where `s[j]` represents the size of each cookie.

**Constraints:**
- `1 <= g.length <= 3 * 10^4`
- `0 <= s.length <= 3 * 10^4`
- `1 <= g[i], s[j] <= 2^31 - 1`

### Output
Return the maximum number of children who can be made content.

### Examples

**Input:**
```text
g = [1, 2, 3]
s = [1, 1]
```

**Output:**
```text
1
```

---

**Input:**
```text
g = [1, 2]
s = [1, 2, 3]
```

**Output:**
```text
2
```

---

**Input:**
```text
g = [1, 2, 3, 4]
s = [1, 2, 3]
```

**Output:**
```text
3
```

---

## 2. Maximum Number of Activities

A problem that teaches greedy algorithms for selecting the maximum number of non-overlapping activities.

You are given a set of activities, where each activity has a start time and an end time. A person can perform only one activity at a time.

You must select activities such that no two selected activities overlap and the total number of selected activities is maximized.

This problem helps build concepts like:
- Greedy algorithms
- Activity selection
- Sorting by finishing time
- Interval scheduling

which are important for solving scheduling and optimization problems efficiently.

**Your task:** Return the maximum number of non-overlapping activities that can be performed.

### Input
An integer `n` representing the number of activities, followed by two arrays `start[]` and `end[]`, where `start[i]` and `end[i]` represent the starting and ending time of the `i`-th activity.

**Constraints:**
- `1 <= n <= 10^5`
- `0 <= start[i] < end[i] <= 10^9`

### Output
Return the maximum number of non-overlapping activities that can be performed.

### Examples

**Input:**
```text
n = 6
start = [1, 3, 0, 5, 8, 5]
end = [2, 4, 6, 7, 9, 9]
```

**Output:**
```text
4
```

---

**Input:**
```text
n = 4
start = [1, 2, 3, 4]
end = [2, 3, 4, 5]
```

**Output:**
```text
4
```

---
