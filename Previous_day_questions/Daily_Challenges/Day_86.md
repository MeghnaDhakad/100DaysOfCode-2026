<h2 align="center">Week 13 Day 86 (08/09/2026)</h2>

## 1. Longest Palindrome (LeetCode #409)

A problem that teaches greedy counting for constructing the longest possible palindrome from the available characters.

You are given a string `s` consisting of lowercase and/or uppercase English letters. You need to determine the maximum length of a palindrome that can be built using its characters.

Letters are case sensitive. For example, `"Aa"` cannot form a palindrome of length `2` because `'A'` and `'a'` are different characters.

This problem helps build concepts like:
- Greedy algorithms
- Frequency counting
- Hashing
- Palindrome construction

which are important for solving character counting and optimization problems efficiently.

**Your task:** Return the maximum length of a palindrome that can be constructed using the characters of `s`.

### Input
A string:
- `s`, containing lowercase and/or uppercase English letters.

**Constraints:**
- `1 <= s.length <= 2000`
- `s` consists of lowercase and/or uppercase English letters only.

### Output
Return the length of the longest palindrome that can be built with the characters of `s`.

### Examples

**Input:**
```text
s = "abccccdd"
```

**Output:**
```text
7
```

---

**Input:**
```text
s = "a"
```

**Output:**
```text
1
```

---

**Input:**
```text
s = "Aa"
```

**Output:**
```text
1
```

---

## 2. Fractional Knapsack

A problem that teaches greedy algorithms for maximizing the total value obtained within a fixed knapsack capacity.

You are given a set of items, where each item has a value and a weight, along with a knapsack that has a fixed capacity.

You are allowed to take whole items or fractions of items. The goal is to maximize the total value placed in the knapsack.

This problem helps build concepts like:
- Greedy algorithms
- Value-to-weight ratio
- Sorting
- Optimization

which are important for solving resource allocation and optimization problems efficiently.

**Your task:** Return the maximum total value that can be obtained by selecting whole or fractional parts of the items.

### Input
An integer `n` representing the number of items, followed by two arrays `value[]` and `weight[]`, where `value[i]` and `weight[i]` represent the value and weight of the `i`-th item. Also, an integer `capacity` representing the maximum weight the knapsack can hold.

**Constraints:**
- `1 <= n <= 10^5`
- `1 <= value[i], weight[i] <= 10^9`
- `1 <= capacity <= 10^9`

### Output
Return the maximum total value that can be obtained by filling the knapsack. The answer may be a fractional value.

### Examples

**Input:**
```text
n = 3
value = [60, 100, 120]
weight = [10, 20, 30]
capacity = 50
```

**Output:**
```text
240
```

---
