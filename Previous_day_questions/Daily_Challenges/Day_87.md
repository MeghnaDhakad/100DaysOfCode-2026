<h2 align="center">Week 13 Day 87 (09/09/2026)</h2>

## 1. Lemonade Change (LeetCode #860)

A problem that teaches greedy algorithms for providing the correct change while processing customers in order.

At a lemonade stand, each lemonade costs `$5`. Customers are standing in a queue and buy lemonade one at a time in the order specified by `bills`.

Each customer pays with either a `$5`, `$10`, or `$20` bill. You must provide the correct change so that every customer effectively pays `$5`. Initially, you do not have any change.

This problem helps build concepts like:
- Greedy algorithms
- Simulation
- Counting
- Decision making

which are important for solving sequential transaction problems efficiently.

**Your task:** Determine whether you can successfully provide the correct change to every customer in the given order.

### Input
An integer array:
- `bills`, where `bills[i]` represents the bill paid by the `i`-th customer.

**Constraints:**
- `1 <= bills.length <= 10^5`
- `bills[i]` is either `5`, `10`, or `20`.

### Output
Return `true` if every customer can receive the correct change; otherwise, return `false`.

### Examples

**Input:**
```text
bills = [5, 5, 5, 10, 20]
```

**Output:**
```text
true
```

---

**Input:**
```text
bills = [5, 5, 10, 10, 20]
```

**Output:**
```text
false
```

---

**Input:**
```text
bills = [5, 5, 5, 5, 10, 10, 20]
```

**Output:**
```text
true
```

---

## 2. Minimum Number of Coins

A problem that teaches greedy algorithms for selecting the minimum number of coins needed to form a target amount.

You are given a set of coin denominations and a target amount. Each coin denomination can be used any number of times.

The given denominations form a system in which the greedy approach of selecting the largest possible denomination at each step produces an optimal solution.

This problem helps build concepts like:
- Greedy algorithms
- Sorting
- Coin selection
- Optimization

which are important for solving resource allocation and optimization problems efficiently.

**Your task:** Determine the minimum number of coins needed to make the given amount using a greedy algorithm. At each step, select the largest denomination that does not exceed the remaining amount.

### Input
An integer `n` representing the number of coin denominations, followed by an array `coins[]` containing the available coin denominations. Also, an integer `amount` representing the target amount.

**Constraints:**
- `1 <= n <= 10^5`
- `1 <= coins[i] <= 10^9`
- `0 <= amount <= 10^9`
- The given coin denominations form a system for which the greedy approach produces an optimal solution.

### Output
Return the minimum number of coins required to make the given amount. If the amount cannot be formed using the given denominations, return `-1`.

### Examples

**Input:**
```text
n = 5
coins = [1, 5, 10, 25, 50]
amount = 87
```

**Output:**
```text
5
```

---
